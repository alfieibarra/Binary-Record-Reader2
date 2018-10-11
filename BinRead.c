#include <stdio.h>
#include <stdlib.h>

typedef struct {
	unsigned char id: 2;
	unsigned char cat: 2;
	unsigned char engaged: 1;
	unsigned char :3;
}Misc;

typedef struct {
	unsigned short year: 7;
	unsigned short month: 4;
	unsigned short day: 5;
	unsigned short hour: 5;
	unsigned short minute: 6;
	unsigned short :5;
	unsigned short second: 6;
	unsigned short :10;
}Date;

typedef struct {
	float lat;
	float lon;
	short alt;
	char name[5];
	Misc misc;
	Date date;
} Field;

int main()
{
	FILE *ifile = fopen("tracks2.dat", "rb");
	Field f_struct;

	while (fread(&f_struct, 22, 1, ifile) != 0) {
		printf("Lat: %.1f", f_struct.lat);
		printf(" lon: %.1f", f_struct.lon);
		printf(" alt: %d", f_struct.alt);
		printf(" name: ");
		for (int i = 0; i < 5; i++) {
			printf("%c", f_struct.name[i]);
		}
		switch(f_struct.misc.id) {
			case 0:
				printf(" id: unknown");
				break;
			case 1:
				printf(" id: friend");
				break;
			case 2:
				printf(" id: foe");
				break;
			case 3:
				printf(" id: neutral");
				break;
		}
		switch(f_struct.misc.cat) {
			case 0:
				printf(" cat: ship");
				break;
			case 1:
				printf(" cat: ground vehicle");
				break;
			case 2:
				printf(" cat: airplane");
				break;
		}
		if( f_struct.misc.engaged == 1 ) {
			printf( " engaged");
		}
		printf(" reported: 20%d/", f_struct.date.year);
		switch(f_struct.date.month) {
			case 1:
				printf("jan/");
				break;
			case 2:
				printf("feb/");
				break;
			case 3:
				printf("mar/");
				break;
			case 4:
				printf("apr/");
				break;
			case 5:
				printf("may/");
				break;
			case 6:
				printf("jun/");
				break;
			case 7:
				printf("jul/");
				break;
			case 8:
				printf("aug/");
				break;
			case 9:
				printf("sep/");
				break;
			case 10:
				printf("oct/");
				break;
			case 11:
				printf("nov/");
				break;
			case 12:
				printf("dec/");
				break;
		}
		printf("%02d", f_struct.date.day);
		printf(" %02d:", f_struct.date.hour);
		printf("%02d:", f_struct.date.minute);
		printf("%02d", f_struct.date.second);
		printf("\n");
	}
	
	fclose(ifile);
	return 0;
}
