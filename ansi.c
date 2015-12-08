#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


double cp437_to_utf8[256] = {0x0000, 0x263A, 0x263B, 0x2665, 0x2666, 0x2663, 0x2660, 0x2022, 0x25D8, 0x25CB, 0x25D9, 0x2642, 0x2640, 0x266A, 0x266B, 0x263C, 0x25BA, 0x25C4, 0x2195, 0x203C, 0x00B6, 0x00A7, 0x25AC, 0x21A8, 0x2191, 0x2193, 0x2192, 0x2190, 0x221F, 0x2194, 0x25B2, 0x25BC, 0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027, 0x0028, 0x0029, 0x002A, 0x002B, 0x002C, 0x002D, 0x002E, 0x002F, 0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037, 0x0038, 0x0039, 0x003A, 0x003B, 0x003C, 0x003D, 0x003E, 0x003F, 0x0040, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047, 0x0048, 0x0049, 0x004A, 0x004B, 0x004C, 0x004D, 0x004E, 0x004F, 0x0050, 0x0051, 0x0052, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057, 0x0058, 0x0059, 0x005A, 0x005B, 0x005C, 0x005D, 0x005E, 0x005F, 0x0060, 0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067, 0x0068, 0x0069, 0x006A, 0x006B, 0x006C, 0x006D, 0x006E, 0x006F, 0x0070, 0x0071, 0x0072, 0x0073, 0x0074, 0x0075, 0x0076, 0x0077, 0x0078, 0x0079, 0x007A, 0x007B, 0x007C, 0x007D, 0x007E, 0x2302, 0x00C7, 0x00FC, 0x00E9, 0x00E2, 0x00E4, 0x00E0, 0x00E5, 0x00E7, 0x00EA, 0x00EB, 0x00E8, 0x00EF, 0x00EE, 0x00EC, 0x00C4, 0x00C5, 0x00C9, 0x00E6, 0x00C6, 0x00F4, 0x00F6, 0x00F2, 0x00FB, 0x00F9, 0x00FF, 0x00D6, 0x00DC, 0x00A2, 0x00A3, 0x00A5, 0x20A7, 0x0192, 0x00E1, 0x00ED, 0x00F3, 0x00FA, 0x00F1, 0x00D1, 0x00AA, 0x00BA, 0x00BF, 0x2310, 0x00AC, 0x00BD, 0x00BC, 0x00A1, 0x00AB, 0x00BB, 0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0x2561, 0x2562, 0x2556, 0x2555, 0x2563, 0x2551, 0x2557, 0x255D, 0x255C, 0x255B, 0x2510, 0x2514, 0x2534, 0x252C, 0x251C, 0x2500, 0x253C, 0x255E, 0x255F, 0x255A, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256C, 0x2567, 0x2568, 0x2564, 0x2565, 0x2559, 0x2558, 0x2552, 0x2553, 0x256B, 0x256A, 0x2518, 0x250C, 0x2588, 0x2584, 0x258C, 0x2590, 0x2580, 0x03B1, 0x00DF, 0x0393, 0x03C0, 0x03A3, 0x03C3, 0x00B5, 0x03C4, 0x03A6, 0x0398, 0x03A9, 0x03B4, 0x221E, 0x03C6, 0x03B5, 0x2229, 0x2261, 0x00B1, 0x2265, 0x2264, 0x2320, 0x2321, 0x00F7, 0x2248, 0x00B0, 0x2219, 0x00B7, 0x221A, 0x207F, 0x00B2, 0x25A0, 0x00A0};


void print_utf8 (unsigned int ch) {
	unsigned char x;
	if (ch < 0x80) {
		x = ch;
		printf("%c",x);
	}
	else if (ch < 0x800) {
		x = (ch>>6) | 0xC0;
		printf("%c",x);
		x = (ch & 0x3F) | 0x80;
		printf("%c",x);
	}
	else if (ch < 0x10000) {
		x = (ch>>12) | 0xE0;
		printf("%c",x);
		x = ((ch>>6) & 0x3F) | 0x80;
		printf("%c",x);
		x = (ch & 0x3F) | 0x80;
		printf("%c",x);
	}
	else if (ch < 0x110000) {
		x = (ch>>18) | 0xF0;
		printf("%c",x);
		x = ((ch>>12) & 0x3F) | 0x80;
		printf("%c",x);
		x = ((ch>>6) & 0x3F) | 0x80;
		printf("%c",x);
		x = (ch & 0x3F) | 0x80;
		printf("%c",x);
	}
}


void print_cp437_chars() {
	unsigned int x = 0;
	unsigned char y = 0;
	for (x=0; x<256; x++) {
		if (y==0) printf("\n  ");
		y++;
		if (y==32) y=0;
		print_utf8(cp437_to_utf8[x]);
	}
}

int str_to_num(const char *str) {
	int len = strlen(str);
	int i;
	int result = (str[0] - '0');
	for(i=1; i<len; i++) {
		result += 10 * (str[i] - '0');
	}
	return result;
}


int main( int argc, char *argv[] ) {

	if (argc < 2) {
		printf("usage: %s ansifile\n",argv[0]);
		printf("...or: %s -rtfm\n",argv[0]);
	}
	else {
		int i;
		bool loadansi = true;
		char file_arg = 1;
		int cursor_x = 0;
		bool escape_seq = false;
		char cur_esc_seq[25];
		char cur_esc_param[5];
		int esc_x;
		int cursor_x_save;
		const char *errstr;

		if (argv[1][0]=='-') {
			file_arg = 2;

			switch (argv[1][1]) {
				case 'h':
				case 'r':
					loadansi = false;
					printf("\nU N T - A N S I\n");
					printf("you are reading teh fakking manual\n\n");
					printf("  -rtfm or -h       display this message\n");
					printf("  -cp437 or -c      display utf-8 characters of cp437\n");
					printf("\n");
					break;
				case 'c':
					loadansi = false;
					printf("cp437 as displayed with utf-8\n");
					print_cp437_chars();
					printf("\n\n");
					break;
			}
		}
		
		if (loadansi==false) return(0);

		FILE *file;
		file = fopen(argv[file_arg],"r");
		
		if (file==0) {
			printf("error reading \"%s\"\n",argv[file_arg]);
			loadansi = false;
		}

		if (loadansi==true) {
			unsigned int x;
			while ((x=fgetc(file))!=EOF) {
				// magic sauce 192kbps modem style
				//usleep(5);
				// NO WE DO 14.4kbps
				usleep(69);
				// check if escape sequence must be terminated
				if ((x >= 65 && x <= 90) || (x >= 97 && x <= 122)) {
					escape_seq = false;
				}
				// check for newline, carraige, and ESC
				if (x==10 || x==13 || x==27) {
					if (x==27) {
						
						for (i = 0; !((x >= 65 && x <= 90) || (x >= 97 && x <= 122)); i++) {
							//c = (char)x;
							cur_esc_seq[i] = (char)x;
							printf("%c", x);
							// shouldn't run into EOF mid escape sequence
							if ((x = fgetc(file)) == EOF) {
								x = 100;
							}
						}
						printf("%c", x);
						for (i = 2; cur_esc_seq[i] != x && cur_esc_seq[i] != ';'; i++) {
							cur_esc_param[i-2] = cur_esc_seq[i];
						}
						printf("%s", " || ");
						printf("%s", cur_esc_param);
						esc_x = str_to_num(cur_esc_param);
						printf("%s", " -- ");
						printf("%d", esc_x);
						// cursor move right
						if (x == 'C') {
							cursor_x += esc_x;	
						}
						// cursor move left
						if (x == 'D') {
							cursor_x -= esc_x;
						}
						// cursor move to column
						if (x == 'G') {
							cursor_x = esc_x;
						}
						// cursor move to position
						if (x == 'H') {
							cursor_x = esc_x;
						}
						// cursor move to position
						if (x == 'f') {
							cursor_x = esc_x;
						}
						// save cursor position
						if (x == 's') {
							cursor_x_save = esc_x;	
						}
						// restore cursor position
						if (x == 'u') {
							cursor_x = cursor_x_save;
						}
						cur_esc_seq[0] = cur_esc_param[0] = '\0';
					}
					if (x==10 || x==13) {
						//sprintf(str, "%d", cursor_x);
						//printf("%s", str);
						char* ass = "ass";
						//printf("%d", cursor_x);
						//printf("%s", ass);
						cursor_x = 0;
					}
					printf("%c", x);
				}
				else {
					print_utf8(cp437_to_utf8[x]);
					if (escape_seq == false) {
						cursor_x++;
					}
				}
				// check for column 80
				if (cursor_x >= 79) {
				/*
					printf("%s", "  ");
				   printf("%d", cursor_x);
					printf("%s", "  ");
					*/
				   //printf("%d", cursor_x);
					printf("%c%c", 10, 13);
					cursor_x = cursor_x % 80;
				}
 
			}
			fclose(file);
		}
		printf("\n");
	}
}


