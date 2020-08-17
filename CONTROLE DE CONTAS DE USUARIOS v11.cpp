// SISTEMA DE CONTROLE DE CONTAS DE USUÁRIOS v1.1
// Aluno ESTÁCIO: Dorcival dos Santos Leite (202003362174)

#include <iostream>
#include <locale>
#include <stdlib.h>
#include <string>

using namespace std;

string validacao() {
	string cara;
	system("cls");
	cout << "AS CONTAS ATUAIS DO SISTEMA SÃO:" << endl;
	cout << "================================" << endl;
	system("net user");
	cout << "-------------------------------------------------------------------------------\n";
	cout << "\nDigite o nome do usuário: ";
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
	cout << "Criaremos a Conta de Usuário: " << usuario << endl;
	system(comando.c_str());
	cout << "Usuário: " << usuario << " criado com sucesso.\n" << endl;
}

void opcao3(){
	string usuario = validacao();
	string comando = "net user " + usuario + " /delete";
	system("cls");
	cout << "Removeremos a Conta de Usuário: " << usuario << endl;
	system(comando.c_str()); 
	cout << "Usuário: " << usuario << " excluída com sucesso.\n" << endl;
}

void opcao4(){
	string usuario = validacao();
	string comando = "net user " + usuario + " *";
	system("cls");
	cout << "Trocaremos a senha da Conta de Usuário: " << usuario << endl;
	system(comando.c_str());  
	cout << "Senha do Usuário: " << usuario << " modificada com sucesso.\n" << endl;
}

void opcao5(){
	string usuario = validacao();
	string comando = "net localgroup Administradores " + usuario + " /add";
	system("cls");
	cout << "Adicionaremos privilégio de ADM a Conta de Usuário: " << usuario << endl;
	system(comando.c_str());   
	cout << "Privilégio ADM de: " << usuario << " adicionado com sucesso.\n" << endl;
}

void opcao6(){
	string usuario = validacao();
	string comando = "net localgroup Administradores " + usuario + " /delete";
	system("cls");
	cout << "Removeremos privilégio de ADM a Conta de Usuário: " << usuario << endl;
	system(comando.c_str()); 
	cout << "Privilégio ADM de: " << usuario << " removido com sucesso.\n" << endl;
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
	cout << "\nEscolha uma das opções abaixo:\n" << endl;
	cout << "[1] Ativar conta interna Administrador" << endl;
	cout << "[2] Criar conta de Usuário" << endl;
	cout << "[3] Remover conta de Usuário" << endl;
	cout << "[4] Alterar senha do Usuário" << endl;
	cout << "[5] Adicionar privilégio de Administrador" << endl;
	cout << "[6] Retirar privilégio de Administrador" << endl;
	cout << "\nDigite a opção desejada (1 - 6): ";
	cin >> op;
			
	while (cin.fail() || op < 1 || op > 6) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "\nOpção inválida. Repita a operação acima."  << endl;
		cin >> op;
	}
	cout << "A opção escolhida foi: " << op << endl;
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