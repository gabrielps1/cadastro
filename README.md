# 📋 Sistema de Cadastro de Clientes em C

Este é um projeto simples de **sistema de administração de clientes**, desenvolvido em linguagem C, utilizando **arquivos `.txt`** como forma de armazenamento local dos dados.

O sistema é executado em terminal e possui funcionalidades básicas para cadastro e listagem de clientes.

---

## 🧩 Funcionalidades

✅ Menu principal com as opções:
- **[1] Cadastrar**: Adiciona um novo cliente ao sistema.
- **[2] Modificar**: Informa ao usuário como modificar manualmente os dados no arquivo.
- **[3] Listar**: Exibe os clientes cadastrados.
- **[4] Remover**: Informa ao usuário como remover manualmente os dados no arquivo.
- **[5] Encerrar**: Encerra o programa.

---

## 🗃 Estrutura do Cadastro

Cada cliente é salvo com as seguintes informações:

- Nome
- E-mail
- CPF

Esses dados são armazenados no arquivo `clientes.txt` localizado na mesma pasta do executável.

---

## 🖥️ Como Executar

1. Compile o programa com um compilador C (ex: GCC):
   ```bash
   gcc -o cadastro main.c
