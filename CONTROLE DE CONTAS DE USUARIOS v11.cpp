// SISTEMA DE CONTROLE DE CONTAS DE USU�RIOS v1.1
// Aluno EST�CIO: Dorcival dos Santos Leite (202003362174)

#include <iostream>
#include <locale>
#include <stdlib.h>
#include <string>

using namespace std;

string validacao() {
	string cara;
	system("cls");
	cout << "AS CONTAS ATUAIS DO SISTEMA S�O:" << endl;
	cout << "================================" << endl;
	system("net user");
	cout << "-------------------------------------------------------------------------------\n";
	cout << "\nDigite o nome do usu�rio: ";
	cin >> cara;
	return cara;
}

void opcao1(){
	system("net user administrador /active:yes");
}

void opcao2() {
	string usuario = validacao();
	string comando = "net user " + usuario + " /add";
	system("cls");
	cout << "Criaremos a Conta de Usu�rio: " << usuario << endl;
	system(comando.c_str());
	cout << "Usu�rio: " << usuario << " criado com sucesso.\n" << endl;
}

void opcao3(){
	string usuario = validacao();
	string comando = "net user " + usuario + " /delete";
	system("cls");
	cout << "Removeremos a Conta de Usu�rio: " << usuario << endl;
	system(comando.c_str()); 
	cout << "Usu�rio: " << usuario << " exclu�da com sucesso.\n" << endl;
}

void opcao4(){
	string usuario = validacao();
	string comando = "net user " + usuario + " *";
	system("cls");
	cout << "Trocaremos a senha da Conta de Usu�rio: " << usuario << endl;
	system(comando.c_str());  
	cout << "Senha do Usu�rio: " << usuario << " modificada com sucesso.\n" << endl;
}

void opcao5(){
	string usuario = validacao();
	string comando = "net localgroup Administradores " + usuario + " /add";
	system("cls");
	cout << "Adicionaremos privil�gio de ADM a Conta de Usu�rio: " << usuario << endl;
	system(comando.c_str());   
	cout << "Privil�gio ADM de: " << usuario << " adicionado com sucesso.\n" << endl;
}

void opcao6(){
	string usuario = validacao();
	string comando = "net localgroup Administradores " + usuario + " /delete";
	system("cls");
	cout << "Removeremos privil�gio de ADM a Conta de Usu�rio: " << usuario << endl;
	system(comando.c_str()); 
	cout << "Privil�gio ADM de: " << usuario << " removido com sucesso.\n" << endl;
}
	
int main() {
	setlocale(LC_ALL,"portuguese");
	
	if (system("net session 2>NUL >NUL")) {
		cout << "O aplicativo DEVE ser executado em MODO ADMINISTRADOR!" << endl;
		return 1;
	}

	int op;
	cout << "==========================================" << endl;
	cout << "   SISTEMA DE CONTROLE DE USUARIOS v1.0   " << endl;
	cout << "==========================================" << endl;
	cout << "\nEscolha uma das op��es abaixo:\n" << endl;
	cout << "[1] Ativar conta interna Administrador" << endl;
	cout << "[2] Criar conta de Usu�rio" << endl;
	cout << "[3] Remover conta de Usu�rio" << endl;
	cout << "[4] Alterar senha do Usu�rio" << endl;
	cout << "[5] Adicionar privil�gio de Administrador" << endl;
	cout << "[6] Retirar privil�gio de Administrador" << endl;
	cout << "\nDigite a op��o desejada (1 - 6): ";
	cin >> op;
			
	while (cin.fail() || op < 1 || op > 6) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "\nOp��o inv�lida. Repita a opera��o acima."  << endl;
		cin >> op;
	}
	cout << "A op��o escolhida foi: " << op << endl;
	system("pause");
					
	switch(op) {
    case 1: opcao1(); break;
    case 2: opcao2(); break;
    case 3: opcao3(); break;
	case 4: opcao4(); break;
    case 5: opcao5(); break;
    case 6: opcao6(); break;
	}
	system("pause");
	return 0;
}