/*---------------------------------------------------------=[public  src]=--*/
/* CGi scann3r v1.56.5 (c) by su1d sh3ll //UnlG 1999                        */
/* public email for any contacts: unlg@hotmail.com                          */
/* http://infected.ilm.net/unlg/                                            */
/* Tested on slackware linux with kernel 2.0.35-2.2.5;Freebsd 2.2.1-3.2     */
/*           IRIX 5.3(thnx 2 hypoclear of lUSt ;-)                          */
/* first release and 60% source c0de by [CKS & FDISK] (thx for first scaner)*/
/*                                                    (and secont too ;-)   */
/* greetz 2: Packet st0rm and Ken(hey! :-), ADM crew, echo security and CKS */
/*           el8.org users, #c0de, rain.forest.puppy/[WT], [THC]            */
/*           MnemoniX, hypoclear of lUSt, codex , Mixter, Void, Surgeon     */
/*           K.A.L.U.G.(brrr...), Epicurus, f0bic                           */
/* c0ming s00n: nothing :-)                                                 */
/*------------------------------=E[ 09:53am 10-05-1999  unl!m!ted group ]3=-*/

/* sourcec0de protected by su1d sh3ll //UnlG ;-) */
/* idea by b.$. //UnlG                           */
/* i like hex!!!! :-p                            */

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <arpa/nameser.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <signal.h>

void main (int argc, char *argv[])
{        /* lame style, but i don't like the c0de rippers :-( */
   int sock,debugm=0; struct in_addr addr; struct sockaddr_in sin;
   struct hostent *he; unsigned long start,end; unsigned long counter;
   char foundmsg[] = "\x32\x30\x30"; 
   char notfoundmsg[] = "\x34\x30\x34"; 
   char *cgistr; char buffer[1024];
   int count=0; int numin;  int curport=0x50; int succeess=0;
   char cgibuff[1024];   char *cnm[120];
   char *buff[120];       /* hehehe 120.....*/
   char meeeeeeeeeeee[] = "\x73\x75\x31\x64\x20\x73\x68\x33\x6c\x6c\20"
                          "\x2f\x2f\x55\x6e\x6c\x47\x20\x31\x39\x39\x39";
buff[1]  = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x75n\x6c\x67\x31.\x31\x20\x48\x54\x54\x50\x2f\x31.\x30\n\n";
buff[2]  = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x75\x6el\x67\x31.\x32\x20\x48\x54\x54\x50\x2f\x31.\x30\n\n";
buff[3]  = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x72\x77w\x77\x73h\x65\x6c\x6c.\x70l\x20H\x54T\x50\x2f\x31.0\n\n";
buff[4]  = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x67\x48\x2e\x63h\x67\x69\x20H\x54T\x50\x2f\x31.0\n\n";
buff[5]  = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x70\x68\x66\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[6]  = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x43o\x75\x6e\x74.\x63\x67i\x20\x48\x54\x54\x50\x2f\x31.\x30\n\n";
buff[7]  = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x74\x65\x73\x74\x2d\x63\x67\x69\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[8]  = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x6e\x70h\x2d\x74\x65\x73\x74\x2d\x63\x67\x69\x20\x48\x54\x54\x50\x2f\x31.\x30\n\n";
buff[9]  = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x6e\x70\x68\x2d\x70\x75\x62\x6c\x69\x73\x68\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[10]  = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x70\x68\x70\x2e\x63\x67\x69\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[11]  = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x70\x68\x70\x2e\x63\x67\x69\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[12] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x68\x61\x6e\x64\x6c\x65\x72\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[13] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "w\x65\x62g\x61\x69\x73\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[14] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x77\x65\x62\x73\x65\x6e\x64m\x61\x69\x6c\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[15] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x77\x65\x62\x64\x69\x73\x74\x2e\x63\x67\x69\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[16] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x66\x61\x78\x73\x75\x72\x76\x65\x79\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[17] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "h\x74\x6d\x6c\x73\x63\x72\x69\x70\x74\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[18] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x70\x66\x64\x69\x73\x70\x6c\x61\x79\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[19] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x70\x65\x72\x6c\x2e\x65x\x65\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[20] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x77\x77\x77\x62\x6f\x61\x72\x64\x2e\x63\x67\x69\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[21] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x77\x77\x77\x62\x6f\x61\x72\x64\x2e\x70\x6c\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[22] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x77\x77\x77\x2d\x73\x71l\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[23] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x76\x69\x65\x77\x2d\x73\x6f\x75\x72\x63\x65\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[24] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x63\x61\x6d\x70\x61\x73\x20\x48\x54\x54\x50\x2f\x31.\x30\n\n";
buff[25] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x61\x67\x6c\x69\x6d\x70\x73\x65\x20\x48\x54\x54P\x2f\x31\x2e\x30\n\n";
buff[26] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x67\x6c\x69\x6d\x70\x73\x65\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[27] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x6d\x61\x6e\x2e\x73\x68\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[28] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x41\x54\x2d\x61\x64\x6d\x69\x6e\x2e\x63\x67\x69\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[29] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x66\x69\x6c\x65\x6d\x61\x69\x6c\x2e\x63\x67\x69\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[30] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x6d\x61\x69\x6c\x6c\x69\x73\x74\x2e\x63\x67\x69\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[31] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x6a\x6a\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[32] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x69\x6e\x66\x6f\x32\x77\x77\x77\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[33] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x66\x69\x6c\x65\x73\x2e\x70\x6c\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[34] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x66\x69\x6e\x67\x65\x72\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[35] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x62\x6e\x62\x66\x6f\x72\x6d\x2e\x63\x67\x69\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[36] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x73\x75\x72\x76\x65\x79\x2e\x63\x67\x69\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[37] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x41\x6e\x79\x46\x6f\x72\x6d\x32\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[38] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "t\x65x\x74\x63\x6f\x75\x6e\x74\x65\x72\x2e\x70\x6c\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[39] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x63\x6c\x61\x73\x73\x69\x66\x69\x65\x64\x73\x2e\x63\x67\x69\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[40] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x65\x6e\x76\x69\x72\x6f\x6e\x2e\x63\x67\x69\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[41] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x77\x72\x61\x70\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[42] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x63\x67\x69\x77\x72\x61\x70\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[43] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x67\x75\x65\x73\x74\x62\x6f\x6f\x6b\x2e\x63\x67\x69\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[44] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x65\x64\x69\x74\x2e\x70\x6c\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[45] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x70\x65\x72\x6c\x73\x68\x6f\x70\x2e\x63\x67\x69\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[46] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x77\x65\x62\x62\x62\x73\x2e\x63\x67\x69\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[47] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x77\x68\x6f\x69\x73\x5f\x72\x61\x77\x2e\x63\x67\x69\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[48] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x41\x6e\x79\x42\x6f\x61\x72\x64\x2e\x63\x67\x69\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[49] = "\x47\x45\x54\x20\x2f\x5f\x76\x74\x69\x5f\x69n\x66\x2e\x68"
  "\x74\x6d\x6c\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[50] = "\x47\x45\x54\x20\x2f\x5f\x76\x74\x69\x5f\x70\x76\x74\x2f"
  "\x75\x73\x65\x72\x73\x2e\x70\x77\x64\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[51] = "\x47\x45\x54\x20\x2f\x5f\x76\x74\x69\x5f\x70\x76\x74\x2f"
  "\x73\x65\x72\x76\x69\x63\x65\x2e\x70\x77\x64\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[52] = "\x47\x45\x54\x20\x2f\x5f\x76\x74\x69\x5f\x70v\x74\x2f"
  "\x61\x75\x74\x68\x6f\x72\x73\x2e\x70\x77\x64\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[53] = "\x47\x45\x54\x20\x2f\x5f\x76\x74\x69\x5f\x70\x77\x64\x2f"
  "\x61\x64\x6d\x69\x6e\x69\x73\x74\x72\x61\x74\x6f\x72\x73\x2e\x70\x77\x64\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[54] = "\x47\x45\x54\x20\x2f\x5f\x76\x74\x69\x5f\x62\x69\x6e\x2f"
  "\x73\x68\x74\x6d\x6c\x2e\x64\x6c\x6c\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[55] = "\x47\x45\x54\x20\x2f\x5f\x76\x74\x69\x5f\x62\x69\x6e\x2f"
  "\x73\x68\x74\x6d\x6c\x2e\x65\x78\x65\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[56] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x64\x6f\x73\x2f"
  "\x61\x72\x67\x73\x2e\x62\x61\x74\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[57] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x77\x69\x6e\x2f"
  "\x75\x70\x6c\x6f\x61\x65\x72\x2e\x65\x78\x65\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[58] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x72\x67\x75\x65\x73\x74\x2e\x65\x78\x65\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[59] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x77g\x75\x65\x73t\x2e\x65x\x65\x20\x48TT\x50\x2f\x31.\x30\n\n";
buff[60] = "\x47\x45\x54\x20\x2f\x73\x63\x72\x69\x70\x74\x73\x2f"
  "\x69\x73\x73\x61\x64\x6d\x6d\x69\x6e\x2f\x62\x64\x69\x72\x2e\x68\x74\x72"
  "\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[61] = "\x47\x45\x54\x20\x2f\x73\x63\x72\x69\x70\x74\x73\x2f"
  "\x43\x47\x49\x6d\x61\x69\x6c\x2e\x65\x78\x65\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[62] = "\x47\x45\x54\x20\x2f\x73\x63\x72\x69\x70\x74\x73\x2f"
  "\x74\x6f\x6f\x6c\x73\x2f\x6e\x65\x77\x64\x73\x6e\x2e\x65\x78\x65\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[63] = "\x47\x45\x54\x20\x2f\x73\x63\x72\x69\x70\x74\x73\x2f"
  "\x66\x70\x63\x6f\x75\x6e\x74\x2e\x65\x78\x65\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[64] = "\x47\x45\x54\x20\x2f\x73\x63\x72\x69\x70\x74\x73\x2f"
  "\x63\x6f\x75\x6e\x74\x65\x72\x2e\x65\x78\x65\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[65] = "\x47\x45\x54\x20\x2f\x73\x63\x72\x69\x70\x74\x73\x2f"
  "\x76\x69\x73\x61\x64\x6d\x69\x6e\x2e\x65\x78\x65\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[66] = "\x47\x45\x54\x20\x2f\x73\x63\x72\x69\x70\x74\x73\x2f"
  "\x70\x65\x72\x6c\x2e\x65\x78\x65\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[67] = "\x47\x45\x54\x20\x2f\x63\x66\x64\x6f\x63\x73\x2f\x65\x78\x70\x65\x6c\x76\x61\x6c\x2f"
  "\x6f\x70\x65\x6e\x66\x69\x6c\x65\x2e\x63\x66\x6d\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[68] = "\x47\x45\x54\x20\x2f\x63\x66\x64\x6f\x63\x73\x2f\x65\x78\x70\x65\x6c\x76\x61\x6c\x2f"
  "\x65\x78\x70\x72\x63\x61\x6c\x63\x2e\x63\x66\x6d\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[69] = "\x47\x45\x54\x20\x2f\x63\x66\x64\x6f\x63\x73\x2f\x65\x78\x70\x65l\x76\x61\x6c\x2f"
  "\x64\x69\x73\x70\x6c\x61\x79\x6f\x70\x65\x6e\x65\x64\x66\x69"
  "\x6c\x65\x2e\x63\x66\x6d\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[70] = "\x47\x45\x54\x20\x2f\x63\x66\x64\x6f\x63\x73\x2f\x65\x78\x70\x65\x6c\x76\x61\x6c\x2f"
  "\x73\x65\x6e\x64\x6d\x61\x69\x6c\x2e\x63\x66\x6d\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[71] = "\x47\x45\x54\x20\x2f\x69\x69\x73\x73\x61\x6d\x70\x6c\x65\x73\x2f\x65\x78\x61\x69\x72\x2f"
  "\x68\x6f\x77\x69\x74\x77\x6f\x72\x6b\x73\x2f\x63\x6f\x64\x65\x62\x72\x77\x73\x2e\x61\x73\x70"
  "\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[72] = "\x47\x45\x54\x20\x2f\x69\x69\x73\x73\x61\x6d\x70\x6c\x65\x73\x2f\x73\x64\x6b\x2f\x61\x73\x70\x2f"
  "\x64\x6f\x63\x73\x2f\x63\x6f\x64\x65\x62\x72\x77\x73\x2e\x61\x73\x70"
  "\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[73] = "\x47\x45\x54\x20\x2f\x6d\x73\x61\x64\x73\x2f\x53\x61\x6d\x70\x6c\x65\x73\x2f"
  "\x53\x45\x4c\x45\x43\x54\x4f\x52\x2f\x73\x68\x6f\x77\x63\x6f\x64\x65\x2e\x61\x73\x70"
  "\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[74] = "\x47\x45\x54\x20\x2f\x73\x65\x61\x72\x63\x68\x39\x37\x2e\x76\x74"
  "\x73\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[75] = "\x47\x45\x54\x20\x2f\x63\x61\x72\x62\x6f\x2e\x64\x6c\x6c"
  "\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[76] = "\x47\x45\x54\x20\x2f\x64\x6f\x6d\x63\x66\x67\x2e\x6e\x73\x66\x2f"
  "\x3f\x6f\x70\x65\x6e\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";  
buff[77] = "\x47\x45\x54\x20\x2f\x3f\x50\x61\x67\x65\x53\x65\x72\x76\x69\x63"
      "\x65\x73\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n"; 
buff[78] = "\x47\x45\x54\x20\x2f\x2e\x2e\x2e\x2e\x2e\x2e\x2e\x2e\x2f\x61\x75\x74"
 "\x6f\x65\x78\x65\x63\x2e\x62\x61\x74\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";  
buff[79] = "\x47\x45\x54\x20\x2f\x73\x63\x72\x69\x70\x74\x73\x2f\x70\x66\x69\x65"
   "\x66\x66\x65\x72\x2e\x62\x61\x74\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";  
buff[80] = "\x47\x45\x54\x20\x2f\x73\x63\x72\x69\x70\x74\x73\x2f\x70\x66\x69\x65"
   "\x66\x66\x65\x72\x2e\x63\x6d\x64\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";  
buff[81] = "\x47\x45\x54\x20\x69\x69\x73\x61\x64\x6d\x70\x77\x64\x2f\x61\x63\x68"
   "\x67\x2e\x68\x74\x72\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[82] = "\x47\x45\x54\x20\x69\x69\x73\x61\x64\x6d\x70\x77\x64\x2f\x61\x63\x68"
   "\x67\x32\x2e\x68\x74\x72\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n"; 
buff[83] = "\x47\x45\x54\x20\x69\x69\x73\x61\x64\x6d\x70\x77\x64\x2f\x61\x63\x68"
   "\x67\x33\x2e\x68\x74\x72\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n"; 
buff[84] = "\x47\x45\x54\x20\x69\x69\x73\x61\x64\x6d\x70\x77\x64\x2f\x61\x63\x68"
   "\x67\x34\x2e\x68\x74\x72\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n"; 
buff[85] = "\x47\x45\x54\x20\x69\x69\x73\x61\x64\x6d\x70\x77\x64\x2f\x61\x63\x68"
   "\x67\x34\x62\x2e\x68\x74\x72\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n"; 
buff[86] = "\x47\x45\x54\x20\x69\x69\x73\x61\x64\x6d\x70\x77\x64\x2f\x61\x6e\x6f"
   "\x74\x2e\x68\x74\x72\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";  
buff[87] = "\x47\x45\x54\x20\x69\x69\x73\x61\x64\x6d\x70\x77\x64\x2f\x61\x6e\x6f"
   "\x74\x33\x2e\x68\x74\x72\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n"; 
buff[88] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f\x64\x61\x79\x35"
   "\x64\x61\x74\x61\x63\x6f\x70\x69\x65\x72\x2e\x63\x67\x69\x20\x48\x54\x54"
   "\x50\x2f\x31\x2e\x30\n\n";  
buff[89] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f\x64\x61\x79\x35"
   "\x64\x61\x74\x61\x6e\x6f\x74\x69\x66\x69\x65\x72\x2e\x63\x67\x69\x20\x48\x54\x54"
   "\x50\x2f\x31\x2e\x30\n\n";  
buff[90] = "\x47\x45\x54\x20\x2f\x5f\x41\x75\x74\x68\x43\x68\x61\x6e\x67\x65"
   "\x55\x72\x6c\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";  
buff[91] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
   "\x70\x61\x73\x73\x77\x64\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";  
buff[92] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
   "\x70\x61\x73\x73\x77\x64\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";  
buff[93] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
   "\x70\x61\x73\x73\x77\x6f\x72\x64\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[94] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f\x70\x61\x73\x73"
  "\x77\x6f\x72\x64\x2e\x74\x78\x74\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n"; 
buff[95] = "\x47\x45\x54\x20\x2f\x73\x65\x73\x73\x69\x6f\x6e\x2f\x61\x64\x6d\x6e"
  "\x6c\x6f\x67\x69\x6e\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n"; 
buff[96] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x61\x78\x2e\x63\x67\x69\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";
buff[97] = "\x47\x45\x54\x20\x2f\x63\x67\x69\x2d\x62\x69\x6e\x2f"
  "\x61\x78\x2d\x61\x64\x6d\x69\x6e\x2e\x63\x67\x69\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n";

 cnm [1]  = "\x75\x6e\x6c\x67\x31\x2e\x31\x20\x20\x20\x20\x20\x20\x20\x20\x20";
 cnm [2]  = "\x75\x6e\x6c\x67\x31\x2e\x32\x20\x20\x20\x20\x20\x20\x20\x20\x20";
 cnm [3]  = "\x72\x77\x77\x77\x73\x68\x65\x6c\x6c\x2e\x70\x6c\x20\x20\x20\x20";
 cnm [4]  = "\x67\x48\x2e\x63\x67\x69\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20";
 cnm [5]  = "\x70\x68\x66\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20";
 cnm [6]  = "\x43\x6f\x75\x6e\x74\x2e\x63\x67\x69\x20\x20\x20\x20\x20\x20\x20";
 cnm [7]  = "\x74\x65\x73\x74\x2d\x63\x67\x69\x20\x20\x20\x20\x20\x20\x20\x20";
 cnm [8]  = "\x6e\x70\x68\x2d\x74\x65\x73\x74\x2d\x63\x67\x69\x20\x20\x20\x20";
 cnm [9]  = "\x6e\x70\x68\x2d\x70\x75\x62\x6c\x69\x73\x68\x20\x20\x20\x20\x20";
 cnm [10] = "\x70\x68\x70\x2e\x63\x67\x69\x20\x20\x20\x20\x20\x20\x20\x20\x20";
 cnm [11] = "\x70\x68\x70\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20";
 cnm [12] = "\x68\x61\x6e\x64\x6c\x65\x72\x20\x20\x20\x20\x20\x20\x20\x20\x20";
 cnm [13] = "\x77\x65\x62\x67\x61\x69\x73\x20\x20\x20\x20\x20\x20\x20\x20\x20";
 cnm [14] = "\x77\x65\x62\x73\x65\x6e\x64\x6d\x61\x69\x6c\x20\x20\x20\x20\x20";
 cnm [15] = "\x77\x65\x62\x64\x69\x73\x74\x2e\x63\x67\x69\x20\x20\x20\x20\x20";
 cnm [16] = "\x66\x61\x78\x73\x75\x72\x76\x65\x79\x20\x20\x20\x20\x20\x20\x20";
 cnm [17] = "\x68\x74\x6d\x6c\x73\x63\x72\x69\x70\x74\x20\x20\x20\x20\x20\x20";
 cnm [18] = "\x70\x66\x64\x69\x73\x70\x6c\x61\x79\x20\x20\x20\x20\x20\x20\x20";
 cnm [19] = "\x70\x65\x72\x6c\x2e\x65\x78\x65\x20\x20\x20\x20\x20\x20\x20\x20";
 cnm [20] = "\x77\x77\x77\x62\x6f\x61\x72\x64\x2e\x63\x67\x69\x20\x20\x20\x20";
 cnm [21] = "\x77\x77\x77\x62\x6f\x61\x72\x64\x2e\x70\x6c\x20\x20\x20\x20\x20";
 cnm [22] = "\x77\x77\x77\x2d\x73\x71\x6c\x20\x20\x20\x20\x20\x20\x20\x20\x20";
 cnm [23] = "\x76\x69\x65\x77\x2d\x73\x6f\x75\x73\x63\x65\x20\x20\x20\x20\x20";
 cnm [24] = "\x63\x61\x6d\x70\x61\x73\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20";
 cnm [25] = "\x61\x67\x6c\x69\x6d\x70\x73\x65\x20\x20\x20\x20\x20\x20\x20\x20";
 cnm [26] = "\x67\x6c\x69\x6d\x70\x73\x65\x20\x20\x20\x20\x20\x20\x20\x20\x20";
 cnm [27] = "\x6d\x61\x6e\x2e\x73\x68\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20";
 cnm [28] = "\x41\x54\x2d\x61\x64\x6d\x69\x6e\x2e\x63\x67\x69\x20\x20\x20\x20";
 cnm [29] = "\x66\x69\x6c\x65\x6d\x61\x69\x6c\x2e\x63\x67\x69\x20\x20\x20\x20";
 cnm [30] = "\x6d\x61\x69\x6c\x6c\x69\x73\x74\x2e\x63\x67\x69\x20\x20\x20\x20";
 cnm [31] = "\x6a\x6a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20";
 cnm [32] = "\x69\x6e\x66\x6f\x32\x77\x77\x77\x20\x20\x20\x20\x20\x20\x20\x20";
 cnm [33] = "\x66\x69\x6c\x65\x73\x2e\x70\x6c\x20\x20\x20\x20\x20\x20\x20\x20";
 cnm [34] = "\x66\x69\x6e\x67\x65\x72\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20";
 cnm [35] = "\x62\x6e\x62\x66\x6f\x72\x6d\x2e\x63\x67\x69\x20\x20\x20\x20\x20";
 cnm [36] = "\x73\x75\x72\x76\x65\x79\x2e\x63\x67\x69\x20\x20\x20\x20\x20\x20";
 cnm [37] = "\x41\x6e\x79\x46\x6f\x72\x6d\x32\x20\x20\x20\x20\x20\x20\x20\x20";
 cnm [38] = "\x74\x65\x78\x74\x63\x6f\x75\x6e\x74\x65\x72\x2e\x70\x6c\x20\x20";
 cnm [39] = "\x63\x6c\x61\x73\x73\x69\x66\x69\x65\x64\x73\x2e\x63\x67\x69\x20";
 cnm [40] = "\x65\x6e\x76\x69\x72\x6f\x6e\x2e\x63\x67\x69\x20\x20\x20\x20\x20";
 cnm [41] = "\x77\x72\x61\x70\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20";
 cnm [42] = "\x63\x67\x69\x77\x72\x61\x70\x20\x20\x20\x20\x20\x20\x20\x20\x20";
 cnm [43] = "\x67\x75\x65\x73\x74\x62\x6f\x6f\x6b\x2e\x63\x67\x69\x20\x20\x20";
 cnm [44] = "\x65\x64\x69\x74\x2e\x70\x6c\x20\x20\x20\x20\x20\x20\x20\x20\x20";
 cnm [45] = "\x70\x65\x72\x6c\x73\x68\x6f\x70\x2e\x63\x67\x69\x20\x20\x20\x20";
 cnm [46] = "\x77\x65\x62\x62\x62\x73\x2e\x63\x67\x69\x20\x20\x20\x20\x20\x20";
 cnm [47] = "\x77\x68\x6f\x69\x73\x5f\x72\x61\x77\x2e\x63\x67\x69\x20\x20\x20";
 cnm [48] = "\x41\x6e\x79\x42\x6f\x61\x72\x64\x2e\x63\x67\x69\x20\x20\x20\x20";
 cnm [49] = "\x5f\x76\x74\x69\x5f\x69\x6e\x66\x2e\x68\x74\x6d\x6c\x20\x20\x20";
 cnm [50] = "\x73\x65\x72\x76\x69\x63\x65\x2e\x70\x77\x64\x20\x20\x20\x20\x20";
 cnm [51] = "\x75\x73\x65\x72\x73\x2e\x70\x77\x64\x20\x20\x20\x20\x20\x20\x20";
 cnm [52] = "\x61\x75\x74\x68\x6f\x72\x73\x2e\x70\x77\x64\x20\x20\x20\x20\x20";
 cnm [53] = "\x61\x64\x6d\x69\x6e\x69\x73\x74\x72\x61\x74\x2e\x70\x77\x64\x20";
 cnm [54] = "\x73\x68\x74\x6d\x6c\x2e\x64\x6c\x6c\x20\x20\x20\x20\x20\x20\x20";
 cnm [55] = "\x73\x68\x74\x6d\x6c\x2e\x65\x78\x65\x20\x20\x20\x20\x20\x20\x20";
 cnm [56] = "\x61\x72\x67\x73\x2e\x62\x61\x74\x20\x20\x20\x20\x20\x20\x20\x20";
 cnm [57] = "\x75\x70\x6c\x6f\x61\x64\x65\x72\x2e\x65\x78\x65\x20\x20\x20\x20";
 cnm [58] = "\x72\x67\x75\x65\x73\x74\x2e\x65\x78\x65\x20\x20\x20\x20\x20\x20";
 cnm [59] = "\x77\x67\x75\x65\x73\x74\x2e\x65\x78\x65\x20\x20\x20\x20\x20\x20";
 cnm [60] = "\x62\x64\x69\x72\x2e\x68\x74\x72\x20\x2d\x20\x73\x61\x6d\x70\x6c";
 cnm [61] = "\x43\x47\x49\x6d\x61\x69\x6c\x2e\x65\x78\x65\x20\x20\x20\x20\x20";
 cnm [62] = "\x6e\x65\x77\x64\x73\x6e\x2e\x65\x78\x65\x20\x20\x20\x20\x20\x20";
 cnm [63] = "\x66\x70\x63\x6f\x75\x6e\x74\x2e\x65\x78\x65\x20\x20\x20\x20\x20";
 cnm [64] = "\x63\x6f\x75\x6e\x74\x65\x72\x2e\x65\x78\x65\x20\x20\x20\x20\x20";
 cnm [65] = "\x76\x69\x73\x61\x64\x6d\x69\x6e\x2e\x65\x78\x65\x20\x20\x20\x20";
 cnm [66] = "\x70\x65\x72\x6c\x2e\x65\x78\x65\x20\x20\x20\x20\x20\x20\x20\x20";
 cnm [67] = "\x6f\x70\x65\x6e\x66\x69\x6c\x65\x2e\x63\x66\x6d\x20\x20\x20\x20";
 cnm [68] = "\x65\x78\x70\x72\x63\x61\x6c\x63\x2e\x63\x66\x6d\x20\x20\x20\x20";
 cnm [69] = "\x64\x69\x73\x70\x6f\x70\x65\x6e\x66\x69\x6c\x65\x2e\x63\x66\x6d";
 cnm [70] = "\x73\x65\x6e\x64\x6d\x61\x69\x6c\x2e\x63\x66\x6d\x20\x20\x20\x20";
 cnm [71] = "\x63\x6f\x64\x65\x62\x72\x77\x73\x2e\x61\x73\x70\x20\x20\x20\x20";
 cnm [72] = "\x63\x6f\x64\x65\x62\x72\x77\x73\x2e\x61\x73\x70\x20\x32\x20\x20";
 cnm [73] = "\x73\x68\x6f\x77\x63\x6f\x64\x65\x2e\x61\x73\x70\x20\x20\x20\x20";
 cnm [74] = "\x73\x65\x61\x72\x63\x68\x39\x37\x2e\x76\x74\x73\x20\x20\x20\x20";
 cnm [75] = "\x63\x61\x72\x62\x6f\x2e\x64\x6c\x6c\x20\x20\x20\x20\x20\x20\x20";
 cnm [76] = "\x3f\x6f\x70\x65\x6e\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20";
 cnm [77] = "\x3f\x5d\x61\x67\x65\x53\x65\x72\x76\x69\x63\x65\x73\x20\x20\x20";
 cnm [78] = "\x61\x75\x74\x6f\x65\x78\x65\x63\x2e\x62\x61\x74\x20\x20\x20\x20";
 cnm [79] = "\x70\x66\x69\x65\x66\x66\x65\x72\x2e\x62\x61\x74\x20\x20\x20\x20";
 cnm [80] = "\x70\x66\x69\x65\x66\x66\x65\x72\x2e\x63\x6d\x64\x20\x20\x20\x20";
 cnm [81] = "\x61\x65\x78\x70\x2e\x68\x74\x72\x20\x20\x20\x20\x20\x20\x20\x20";
 cnm [82] = "\x61\x66\x69\x65\x32\x2e\x68\x74\x72\x20\x20\x20\x20\x20\x20\x20";
 cnm [83] = "\x61\x66\x69\x65\x33\x2e\x68\x74\x72\x20\x20\x20\x20\x20\x20\x20";
 cnm [84] = "\x61\x66\x69\x65\x34\x2e\x68\x74\x72\x20\x20\x20\x20\x20\x20\x20";
 cnm [85] = "\x61\x66\x69\x65\x34\x61\x2e\x68\x74\x72\x20\x20\x20\x20\x20\x20";
 cnm [86] = "\x61\x6e\x6f\x74\x2e\x2e\x68\x74\x72\x20\x20\x20\x20\x20\x20\x20";
 cnm [87] = "\x61\x6e\x6f\x74\x33\x2e\x68\x74\x72\x20\x20\x20\x20\x20\x20\x20"; 
 cnm [88] = "\x64\x61\x79\x35\x63\x6f\x70\x69\x65\x72\x2e\x63\x67\x69\x20\x20";
 cnm [89] = "\x64\x61\x79\x35\x64\x61\x74\x61\x2a\x2e\x63\x67\x69\x20\x20\x20";
 cnm [90] = "\x5f\x41\x75\x74\x68\x43\x68\x61\x6e\x67\x65\x55\x72\x6c\x20\x20";
 cnm [91] = "\x70\x61\x73\x73\x77\x64\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20";
 cnm [92] = "\x70\x61\x73\x73\x77\x64\x2e\x74\x78\x74\x20\x20\x20\x20\x20\x20";
 cnm [93] = "\x70\x61\x73\x73\x77\x6f\x72\x64\x20\x20\x20\x20\x20\x20\x20\x20";
 cnm [94] = "\x70\x61\x73\x73\x77\x6f\x72\x64\x2e\x74\x78\x74\x20\x20\x20\x20";
 cnm [95] = "\x61\x64\x6d\x6e\x6c\x6f\x67\x69\x6e\x20\x20\x20\x20\x20\x20\x20";
 cnm [96] = "\x61\x78\x2e\x63\x67\x69\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20";
 cnm [97] = "\x61\x78\x2d\x61\x64\x6d\x69\x6e\x2e\x63\x67\x69\x20\x20\x20\x20";


   printf("\n\x20\x5b\x2d\x2d\x20\x43\x47\x49\x20\x53\x63\x61\x6e\x6e\x65\x72\x20");
   printf("\x76\x2e\x31\x2e\x35\x36\x20\x28\x63\x29\x20\x62\x79\x20");
   printf(meeeeeeeeeeee);
   printf("\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20");
   printf("\x20\x2d\x2d\x5d\n");
   printf("\x20\x5b\x2d\x2d\x20\x68\x74\x74\x70\x3a\x2f\x2f\x69\x6e\x66\x65\x63\x74\x65\x64\x2e\x69\x6c\x6d\x2e\x6e\x65\x74\x2f");
   printf("\x20\x20\x20\x20\x20\x20\x20\x50\x75\x62\x6c\x69\x63\x20\x65\x6d\x61\x69\x6c\x3a\x75\x6e\x6c\x67\x40h\x6f\x74m\x61\x69\x6c\x2e\x63\x6f\x6d\x20\x2d\x2d\x5d\n");
   if (argc<2) { 
      printf("  usage: %s host ", argv[0]);
      printf("\n or: %s host -d  for debug mode\n\n",argv[0]); }
   if (argc>2) { if (strstr("-d",argv[2])) { debugm=1; } }
   if ((he=gethostbyname(argv[1])) == NULL) { herror("gethostbyname"); exit(0); }
   printf("\x53\x74\x61\x72\x74\x69\x6e\x67\x2e\x2e\x2e\n");
   start=inet_addr(argv[1]); counter=ntohl(start);
   sock=socket(AF_INET,SOCK_STREAM,0);
   bcopy(he->h_addr, (char *)&sin.sin_addr,he->h_length);
   sin.sin_family=AF_INET; sin.sin_port=htons(curport);
   if (connect(sock,(struct sockaddr*)&sin,sizeof(sin))!=0)
      {  perror("\x63\x6f\x6e\x6e\x65\x63\x74");  }
   printf("\n\n\t\x20\x5b\x20\x50\x72\x65\x73\x73\x20\x61\x6e\x79\x20k\x65\x79\x20");
   printf("2\x20\x6fu\x74\x20t\x68\x65\x20ht\x74\x70\x64\x20v\x65\x72");
   printf("\x73i\x6f\x6e\x2e\x2e\x2e\x2e\x2e\x2e\x2e\x20\x5d\n"); getchar();
   send(sock, "\x48\x45\x41\x44\x20\x2f\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\n\n" ,17,0);
   recv(sock, buffer,sizeof(buffer),0); printf("%s", buffer); close(sock);
   printf("\n\t\x20\x5b\x20\x50\x72\x65\x73\x73\x20\x61\x6e\x79\x20\x6b\x65\x79\x20");
   printf("\x32\x20s\x65\x61\x72\x63\x68\x20\x34\x20\x43\x47\x69\x20");
   printf("s\x74\x75\x66\x66\x2e\x2e\x2e\x2e\x2e\x2e\x20\x5d\n"); getchar();
   while(count++ <97) /* huh! 97 cgi.... */
   {         
   sock=socket(AF_INET,SOCK_STREAM,0);
   bcopy(he->h_addr,(char *)&sin.sin_addr,he->h_length);
   sin.sin_family=AF_INET; sin.sin_port=htons(curport);
   if (connect(sock, (struct sockaddr*)&sin, sizeof(sin)) !=0 )
   { perror("c\x6fnn\x65\x63t");  }
   for (numin=0;numin<1024;numin++)
   { cgibuff[numin] = '\0';       }
   send (sock, buff[count], strlen(buff[count]),0);
   recv(sock, cgibuff,sizeof(cgibuff),0); cgistr = strstr(cgibuff,foundmsg);
   if (cgistr != NULL) {
   printf("\x53\x65\x61\x72\x63\x69\x6e\x67\x20\x66\x6f\x72\x20 %s \x20",cnm[count]);
   printf(":\x20\x46\x6f\x75\x6e\x64\x20\x21\x21\x20\x3b\x29\n"); ++succeess; }
   if (debugm==1) { printf("\n\n\x2d--\x2d\x2d------\x2d----\x2d----\x2d--\n");
   printf("%s",cgibuff);
   printf("\n\n\x2d--\x2d\x2d------\x2d----\x2d----\x2d--\n");
   printf("\x50\x72\x65\x73\x73\x20\x61\x6e\x79\x20k\x65\x79\x20\x32\x20\x63\x6f");
   printf("\x6e\x74\x69\x6eu\x65\x2e\x2e\x2e\x2e\x2e\x2e\n"); getchar();
   }  close(sock); }
   if (!succeess)
   { printf("\x68\x65\x79\x20\x64\x75\x64\x65\x21\x20\x62\x61\x64\x20\x6e\x65\x77\x73\x2e\x2e\x2e\x2e\x2e");
   printf("\x6e\x30\x74h\x31\x6eg\x20\x2e\x2e\x2e\x20");
   printf("\x4e\x4e\x30\x30\x30\x54\x54\x54\x48\x31\x31\x31\x4e\x4e\x47\x21\x20:\x2d\x29\n"); }
   else { printf("\x2e\x2e.h\x61v\x65\x20\x61\x20\x6ei\x63\x65\x20h\x61\x63\x6b");
   printf("\x2e\x2e\x2e\x20\x2d\x20");
   printf("\x66\x6f\x75\x6e\x64\x20%d\x20\x43\x47\x69\x73\n",succeess); }
   exit(0);
}       /*  ph34r my c0de?! ;-)                    */
        /*   hey p1ple i can print binary! ;-)))   */

/* EOF - UnlG - EOF - UnlG - EOF - UnlG - EOF - UnlG - EOF - UnlG -EOF */

/*           ?=-?? passed thru infected network  ??-=?         */
/*           ?=-??   http://infected.ilm.net/    ??-=?         */
