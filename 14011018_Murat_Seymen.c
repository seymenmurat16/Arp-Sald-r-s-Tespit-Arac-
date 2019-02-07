#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int i,j,satir;
	const char filename[]="/proc/net/arp"; // arp tablosunun tutulduðu yer
	char ip[10][15],mac[10][18],output[20];
	FILE *fs;
	while(1){
		i=0; // Dosyayý her açtýðýmda i ve j yi sýfýlýyorum  
		j=0;
		fs=fopen(filename,"r");
		while(!feof(fs)){ // Dosyada  bir düzen var bu düzene göre mac ve ip adresini alýyorum
			fscanf(fs,"%s",output);
			if(i==0 && j!=0 ){ // eðer satýr baþýndaysa ve bu dosyadaki ilk satýr deðile (çünkü ilk satýr tanýmlar var) ip adresi olduðunu anlayýp alýyorum 
				strcpy(ip[j-1],output);
			}
			if(i==3 && j!=0 ){ // eðer satýrdaki 4.okunan veri ise mac adresi olduðunu anlýyorum
				strcpy(mac[j-1],output);
			}
			i++; // her veri okunduktan sonra 1 arttýrýyorum
			if(i==6 && j!=0){ // eðer ilk satýrý okumayý bitirdiyse her 6.veriyi okuduktan sonra satýr baþýna geçtiði için i yi sýfýrlayýp j yi arttýrýyorum
				i=0;
				j++;
			}
			if(i==9){ // ilk satýrý okurken j=0 ve ilk satýrda 9 veri var bu verileri geçtikten sonra j yi 1 yapýyorum
				j=1;
				i=0;
			}
		}
		fclose(fs);
		satir=j-1; // kaç satýr ip ve mac adresini aldýðýný satira atýyorum
		for(i=0;i<satir-1;i++){ 
			for(j=i+1;j<satir;j++){
				if(strcmp(mac[i],mac[j])==0){ // mac adreslerini birbirleri ile karþýlaþtýrýyorum eðer eþitlerse ip adreslerine bakýyorum
					if(strcmp(ip[i],ip[j])!=0){ // eðer mac adresleri ayný olup ip adresleri farklý ise kullanýcýyý bilgilendiriyorum
						printf("Saldiri altindasiniz.\n");
						exit(0);
					}
				}
			}
		}
	}	
	
}



