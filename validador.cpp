#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void desligaCodigo(){
	printf("Valor invalido. Tente novamente mais tarde.\n");
	exit(1);
}

void validaDia(int diaEntrada){
	if(diaEntrada > 31){
		desligaCodigo();
	}	
	else if(diaEntrada < 1){
		desligaCodigo();
	}
}

void validaMes(int mesEntrada, int diaEntrada){
	if(mesEntrada > 12){
		desligaCodigo();
	}
	else if(mesEntrada < 1){
		desligaCodigo();
	}
	else if(mesEntrada == 1 || mesEntrada == 3 || mesEntrada == 5 || mesEntrada == 7 || mesEntrada == 8 || mesEntrada == 10 || mesEntrada == 12){
		validaDia(diaEntrada);
		if(diaEntrada < 31){
			desligaCodigo();
		}
	}
	else if(mesEntrada == 4 || diaEntrada  == 6 || diaEntrada == 9 || diaEntrada == 11){
		validaDia(diaEntrada);
		if(diaEntrada > 30){
			desligaCodigo();
		}
	}
	else if(mesEntrada == 2){
		validaDia(diaEntrada);
		if(diaEntrada > 29){
			desligaCodigo();
		}
	}
}

void validaAno(int anoEntrada, int anoAtual, int mesEntrada, int diaEntrada){
	time_t mytime;
	mytime = time(NULL);
	struct tm tm = *localtime(&mytime);
	anoAtual = tm.tm_year + 1900;
	
	int bissexto;
	bissexto = anoEntrada % 4;
	
	if(anoEntrada > anoAtual){
		desligaCodigo();
	}
	if(bissexto != 0){
		if(mesEntrada == 2){
			if(diaEntrada > 28){
				desligaCodigo();
			}
		}
	}
}

int main() {
	time_t mytime;
	mytime = time(NULL);
	struct tm tm = *localtime(&mytime);
	
    int diaEntrada;
    int mesEntrada;
    int anoEntrada;
    int diaAtual;
    int mesAtual;
    int anoAtual;
    int anoIdade;
    int mesIdade;
    int diaIdade;
    
	diaAtual = tm.tm_mday;
    mesAtual = tm.tm_mon +1 ;
    anoAtual = tm.tm_year + 1900;

    printf("Dia do seu nascimento: ");
    scanf("%d", &diaEntrada);
    validaDia(diaEntrada);
    
    printf("\nMes do seu nascimento: ");
    scanf("%d", &mesEntrada);
    validaMes(mesEntrada, diaEntrada);
    
	printf("\nAno do seu nascimento: ");
    scanf("%d", &anoEntrada);
    validaAno(anoEntrada, anoAtual, mesEntrada, diaEntrada);

    anoIdade = anoAtual - anoEntrada;
    
    if(mesEntrada > mesAtual){
    	mesIdade = 12 - mesEntrada + mesAtual;
	}
    else if(mesAtual > mesEntrada){
    	mesIdade = mesAtual - mesEntrada;
	}
    
    if(diaEntrada > diaAtual){
    	diaAtual = 30 - diaEntrada + diaAtual;
	}
	else if(diaAtual > diaEntrada){
    	diaIdade = diaAtual - diaEntrada;
	}
    
    printf("\nData de nascimento: %d/%d/%d\n\n", diaEntrada, mesEntrada, anoEntrada);
    printf("Voce tem %d anos\n", anoIdade);
    printf("Voce tem %d mes(es)\n", mesIdade);
    printf("Voce tem %d dia(s)\n", diaIdade);
    
}
