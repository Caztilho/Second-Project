#include <stdio.h>
#include <locale.h>
#include <string.h>

	//N�mero de inscri��o, idade do candidato, maior nota, quantidade de aprovados, total de participantes
	int x, n_i, i_c, maior_nota,  qtd_a, total;
	//Nome do candidato, melhor candidato
	char n_c[100], melhor_candidato[100];
	//Nota do candidato no concurso, porcentagem de aprova��o total
	float nota, p_a;

main(){
	setlocale(LC_ALL, "Portuguese");
	
	printf("Deseja iniciar o processo de sele��o? [1] SIM | [2] N�O\n");
	scanf("%d", &x);
	while((x != 1) && (x != 2)){
		printf("Escolha uma op��o v�lida! [1] SIM | [2] N�O\n");
		scanf("%d", &x);
	}
	
	while(x == 1){
		total++;
		
		printf("Insira seu n�mero de inscri��o: ");
		scanf("%d", &n_i);
		printf("Digite seu nome: ");
		scanf("%s", &n_c);
		printf("Digite sua idade: ");
		scanf("%d", &i_c);
		printf("Insira sua nota do concurso: ");
		scanf("%f", &nota);
		
		while((nota < 0) || (nota > 10)){
			printf("Sua nota precisa estar entre 0 e 10! Tente novamente: ");
			scanf("%f", &nota);
		}
		
		//Aprova��o de candidatos e sele��o do melhor candidato
		if((nota >= 7) && (i_c >= 18)){
			printf("O(A) candidato(a) %s foi aprovado(a)!\n", n_c);
			qtd_a++;
			if(nota > maior_nota){
				maior_nota = nota;
				strcpy(melhor_candidato, n_c);
			}
		} else {
			printf("O(A) candidato(a) %s foi reprovado(a)\n", n_c);
		}

		printf("\nDeseja realizar o processo de sele��o novamente? [1] SIM | [2] N�O\n");
		scanf("%d", &x);
	}
	
	if(total > 0){
		p_a = qtd_a * 100 / total;
	}
	
	
	printf("Quantidade de candidatos aprovados: %d\n", qtd_a);
	printf("Porcentagem de aprova��o em rela��o ao total de participantes: %f%%\n", p_a);
	printf("Melhor candidato: %s | Nota: %d\n", melhor_candidato, maior_nota);
	
}
