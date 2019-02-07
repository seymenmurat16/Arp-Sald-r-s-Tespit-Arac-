#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int i,j,satir;
	const char filename[]="/proc/net/arp"; // arp tablosunun tutuldu�u yer
	char ip[10][15],mac[10][18],output[20];
	FILE *fs;
	while(1){
		i=0; // Dosyay� her a�t���mda i ve j yi s�f�l�yorum  
		j=0;
		fs=fopen(filename,"r");
		while(!feof(fs)){ // Dosyada  bir d�zen var bu d�zene g�re mac ve ip adresini al�yorum
			fscanf(fs,"%s",output);
			if(i==0 && j!=0 ){ // e�er sat�r ba��ndaysa ve bu dosyadaki ilk sat�r de�ile (��nk� ilk sat�r tan�mlar var) ip adresi oldu�unu anlay�p al�yorum 
				strcpy(ip[j-1],output);
			}
			if(i==3 && j!=0 ){ // e�er sat�rdaki 4.okunan veri ise mac adresi oldu�unu anl�yorum
				strcpy(mac[j-1],output);
			}
			i++; // her veri okunduktan sonra 1 artt�r�yorum
			if(i==6 && j!=0){ // e�er ilk sat�r� okumay� bitirdiyse her 6.veriyi okuduktan sonra sat�r ba��na ge�ti�i i�in i yi s�f�rlay�p j yi artt�r�yorum
				i=0;
				j++;
			}
			if(i==9){ // ilk sat�r� okurken j=0 ve ilk sat�rda 9 veri var bu verileri ge�tikten sonra j yi 1 yap�yorum
				j=1;
				i=0;
			}
		}
		fclose(fs);
		satir=j-1; // ka� sat�r ip ve mac adresini ald���n� satira at�yorum
		for(i=0;i<satir-1;i++){ 
			for(j=i+1;j<satir;j++){
				if(strcmp(mac[i],mac[j])==0){ // mac adreslerini birbirleri ile kar��la�t�r�yorum e�er e�itlerse ip adreslerine bak�yorum
					if(strcmp(ip[i],ip[j])!=0){ // e�er mac adresleri ayn� olup ip adresleri farkl� ise kullan�c�y� bilgilendiriyorum
						printf("Saldiri altindasiniz.\n");
						exit(0);
					}
				}
			}
		}
	}	
	
}



