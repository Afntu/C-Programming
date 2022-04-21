#include<unistd.h>
#include<stdio.h>
#include<sys/socket.h>
#include<linux/if_packet.h>
#include<net/ethernet.h>
#include<arpa/inet.h>
#include<pcap.h>

struct ethheader {
u_char ether_dhost[6] ;
u_char ether_shost[6] ;
u_short ether_type ;
};

// IP Header //
struct ipheader{
unsigned char 		iph_ihl:4, //IP header length
			iph_ver:4; //IP version
unsigned char 		iph_tos; //Type of service
unsigned short int	iph_len; //IP Packet length (data+ header )
unsigned short int	iph_ident; //Identification
unsigned short int	iph_flag:3 , //Fragmentation flags
			iph_offset:13; //Flags offset
unsigned char		iph_ttl; //Time to Live
unsigned char		iph_protocol; //Pro tocol type
unsigned short int	iph_chksum; //IP datagram checksum
struct in_addr 	iph_sourceip; //Source IP address
struct in_addr		iph_destip; //Destination IP address
};

void got_packet (u_char *args , const struct pcap_pkthdr *header, const u_char *packet)
{
struct ethheader *eth = (struct ethheader *)packet ;
if(ntohs(eth->ether_type) == 0x0800) { // Ox0800 is IP type
	struct ipheader *ip = (struct ipheader *)(packet + sizeof(struct ethheader));
	printf("From : %s\n ", inet_ntoa(ip->iph_sourceip));
	printf("To : %s\n ", inet_ntoa(ip->iph_destip));


	/* determine protocol*/
	switch(ip->iph_protocol){
		case IPPROTO_TCP:
			printf("Protocol: TCP\n");
			return;
		case IPPROTO_UDP:
			printf("Protocol: UDP\n");
			return ;
		case IPPROTO_ICMP :
			printf("Protocol : ICMP\n");
			return;
		default:
			printf("Protocol: others\n");
			return;
		}
	}
}

int main()
{
	pcap_t *handle;
	char errbuf[PCAP_ERRBUF_SIZE];
	struct bpf_program fp ;
	char filter_exp[] = "ip proto icmp";
	bpf_u_int32 net;
	pcap_if_t *alldevs,*temp;
	
	if(pcap_findalldevs(&alldevs,errbuf)==-1){
		printf("error %s\n",errbuf);
		return -1;
		}
	
	int i=0;
	for(temp=alldevs;temp;temp=temp->next)
		printf("%d : %s\n",i++,temp->name);
	
	// Step 1 : Open live pcap session on NIC with name lo
	handle= pcap_open_live("lo", BUFSIZ , 1, 1000, errbuf);
	if(handle==NULL)printf("%s\n",errbuf);
		
	// Step 2 : Compile filter_exp into BPF psuedo-code
	if(pcap_compile (handle , &fp , filter_exp , 0 , net)<0)
	 	printf("can't compile %s",pcap_geterr(handle));
	pcap_setfilter(handle , &fp); 
	// Step 3 : Capture packets
	pcap_loop(handle , -1, got_packet , NULL );
	pcap_close (handle);
	return 0;
}
