#include <ncurses.h>
#include <string>

using std::string;

char** crearLaberinto(int, int);
void liberarLaberinto(char***, int);
void llenarLaberinto(char**, int, int);
void imprimirLaberinto(char**, int, int);

int main(int argc, char* argv[]){
	initscr();
	refresh();

	int largo = 14;
	int ancho = 25;
	char** labe = NULL;

//	initscr();
	refresh();
	
	labe = crearLaberinto(largo, ancho);
	llenarLaberinto(labe, largo, ancho);
	//imprimirLaberinto(labe, largo, ancho);
	//liberarLaberinto(&labe, largo);
	refresh();

 	//MOVER CURSOR
	int y = 0, x = 0;
	while(true){
		clear();
		imprimirLaberinto(labe, largo, ancho);
		mvaddch(y, x, '*');
	//	imprimirLaberinto(labe, largo, ancho);
		char input = getch();
		if(input == 'A')
			if(y>0)
				y--;
				//imprimirLaberinto(labe, largo, ancho);
		if(input == 'B')
			y++;
			//imprimirLaberinto(labe, largo, ancho);
		if(input == 'C')
			x++;
			//imprimirLaberinto(labe, largo, ancho);
		if(input == 'D')
			x--;
			//imprimirLaberinto(labe, largo, ancho);
	}

	liberarLaberinto(&labe, largo);
	getch();
	endwin();
	
	return 0;
}

char** crearLaberinto(int largo, int ancho ){
	char** m = NULL;
	m = new char*[largo];
	for(int i = 0; i < largo; i++){
		m[i] = new char[ancho];
	}

	return m;
}

void liberarLaberinto(char*** data, int largo){
	for(int i = 0; i < largo; i++){
		delete[] (*data)[i];
	}	
	delete[] *data;
	*data = NULL;
}

void llenarLaberinto(char** laberinto, int largo, int ancho){
//	char c = 242;
	
	for(int i = 0; i < largo; i++){
		for(int j = 0; j < ancho; j++){
			if( i == 0|| i == 13 || j == 0 || j == 24){
				laberinto[i][j] = 'M';
				refresh();
			}else if( i == 1 && (j > 6 && j < 13 ) ) {
				laberinto[i][j] = 'O';
				refresh();
			}else if(i == 2 && ((j > 0 && j < 6) || ( j > 17 && j < 23 )) ){
				laberinto[i][j] = 'O';
				refresh();
			}else if(i == 3 && ( ( j == 5 || j > 8 && j < 17 ) || j == 18) ){
				laberinto[i][j] = 'O';
				refresh();
			}else if( i == 4 && ( j == 3 || j == 7 || j == 18) ){
				laberinto[i][j] = 'O';
				refresh();
			}else if( i == 5 && ( (j > 1 && j < 8) || (j > 8 && j < 18) ) ){
				laberinto[i][j] = 'O';
				refresh();
			}else if( i == 6 && j== 17){
				laberinto[i][j] = 'O';
				refresh();
			}else if( i == 7 && ( (j > 0 && j < 3) || (j > 4 && j < 8) || (j == 9) || (j > 20 && j < 25))){
				laberinto[i][j] = 'O';
				refresh();
			}else if(i == 8 && ( (j == 2) || (j > 8 && j < 18) || (j == 21) ) ){
				 laberinto[i][j] = 'O';
				 refresh();
			}else if(i == 9 && (j == 2 || (j > 3 && j < 6) || j == 21)){
				laberinto[i][j] = '0';
				refresh();
			}else if(i == 10 && (j == 7 || (j > 11 && j < 18) || j == 19)){
				laberinto[i][j] = '0';
				refresh();
			}else if(i == 11 && ( (j > 1 && j < 11) || (j > 18 && j < 25) || j == 15)){
				laberinto[i][j] = '0';
				refresh();
			}else{
				laberinto[i][j] = ' ';
				refresh();
			}
		}
	}
}

void imprimirLaberinto(char** laberinto, int largo, int ancho){
	for(int i = 0; i < largo; i++){
		for(int j = 0; j < ancho; j++){
			//if( i == 0 || i == 13 || j == 0 || j == 24){
				printw ( " %c ", laberinto[i][j]);
				refresh();
			/*}
			if( i == 1 && (j == 7 || j == 8 || j == 9 || j == 10 || j == 11 || j == 12 || j == 13) ){
				printw ( " %c ", laberinto[i][j] );*/
			/*}else{
				printw("[%c]",laberinto[i][j]);
				refresh();
			}*/
		}
		printw("\n");
	}
}
