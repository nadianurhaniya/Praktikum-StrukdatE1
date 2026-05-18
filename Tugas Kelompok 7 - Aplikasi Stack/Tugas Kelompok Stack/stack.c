/* Program   : stack.c */
/* Deskripsi : file BODY modul stack karakter */
/* Nama Kel  : Kelompok 7
            1. Muchammad Yuda Tri Ananda (24060124110142)
            2. Muhammad Kemal Faza (24060124120013)
            3. Nadia Azura Nurhaniya (24060124120019)
            4. Muhammad Zaidaan Ardiyansyah (24060124140200)
            5. Muhammad Farhan Abdul Azis (24060124140166) 
/* Tanggal   : 21-09-2025 */
/***********************************/

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen

/* KONSTRUKTOR */
/* procedure createStack(output S: Tstack)
    {I.S.: - }
    {F.S.: Stack S terdefinisi}
    {Proses mengisi elemen wadah kosong dengan '_', top 0} */
void createStack(Tstack *S)
{
    (*S).top = 0;
    for (int i = 1; i <= 10; i++)
    {
        (*S).wadah[i] = '_';
    }
}

/* SELEKTOR */
/* function infoTop(S: Tstack) -> character
    {mengembalikan nilai elemen puncak} */
int infoTop(Tstack S)
{
    if (S.top > 0)
    {
        return S.wadah[top(S)];
    }
    return -1; // Menandakan stack kosong
}

/* function top(S: Tstack) -> integer
    {mengembalikan posisi puncak} */
int top(Tstack S)
{
    return S.top;
}

/* PREDIKAT */
/* function isEmptyStack(S: Tstack) -> boolean
    {mengembalikan True jika matriks M kosong } */
boolean isEmptyStack(Tstack S)
{
    return (S.top == 0);
}

/* function isFullStack(S: Tstack) -> boolean
    {mengembalikan True jika matriks M penuh } */
boolean isFullStack(Tstack S)
{
    return (S.top == 10);
}

/* MUTATOR */
/* procedure push(input/output S:Tstack, input e:character)
    {I.S.: S, e terdefinisi, S mungkin kosong}
    {F.S.: S tetap, atau infoTop(S) = e}
    {Proses: mengisi elemen e ke puncak S, bila belum penuh} */
void push(Tstack *S, char e)
{
    if (!isFullStack(*S))
    {
        (*S).top++;
        (*S).wadah[(*S).top] = e;
    }
}

/* procedure push(input/output S:Tstack, output e:character)
    {I.S.: S terdefinisi, mungkin kosong}
    {F.S.: S tetap, atau e berisi infoTop(S) lama}
    {Proses: menghapus elemen e dari puncak S, bila belum kosong} */
void pop(Tstack *S, char *e)
{
    if (!isEmptyStack(*S))
    {
        *e = (*S).wadah[(*S).top];
        (*S).wadah[(*S).top] = '_';
        (*S).top--;
    }
}

/* procedure printStack(input S:Tstack)
    {I.S.: S terdefinisi}
    {F.S.: -}
    {Proses: menampilkan semua elemen S ke layar} */
void printStack(Tstack S)
{
    for (int i = 1; i <= 10; i++)
    {
        printf("%c ", S.wadah[i]);
    }
    printf("\n");
}

/* procedure viewStack (input S:Tstack)
    {I.S.: M terdefinisi}
    {F.S.: -}
    {Proses: menampilkan elemen S yang terisi ke layar} */
void viewStack(Tstack S)
{
    for (int i = 1; i <= S.top; i++)
    {
        printf("%c ", S.wadah[i]);
    }
    printf("\n");
}

/* OPERASI LAINNYA */

/* 1. isValidKurung */
/* function isValidKurung(kata:string) → boolean
{I.S.: kata terdefinisi}
{F.S.: Mengembalikan true jika seluruh tanda kurung di kata sesuai pasangan}
{Proses:
  - Jika kurung buka → push ke stack
  - Jika kurung tutup → pop dari stalalu cekck  pasangannya
  - Jika tidak sesuai → return false
  - Setelah semua karakter diproses, jika stack kosong → return true}
{Contoh:
  kata = "{[(A+B)]}" → true
  kata = "{[(A+B)]"  → false} */

boolean isValidKurung(char *str, int n)
{
    // kamus lokal
    Tstack S;
    int i;
    char temp;

    // algoritma
    createStack(&S);
    for (i = 0; i < n; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            push(&S, str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if (isEmptyStack(S))
            {
                return false;
            }
            pop(&S, &temp);

            if ((str[i] == ')' && temp != '(') ||
                (str[i] == '}' && temp != '{') ||
                (str[i] == ']' && temp != '['))
            {
                return false;
            }
        }
    }
    return isEmptyStack(S);
}


/* 2. Undo-Redo */
/* procedure addCommand (input/output Undo: Tstack, Redo: Tstack, input Cmd: character)
{I.S. : Undo & Redo terdefinisi, Cmd terdefinisi}
{F.S. : Cmd masuk ke Undo (push), Redo dikosongkan (createStack)}
{Proses : push Cmd ke Undo, createStack(Redo)}
{Contoh : Undo=['A'], Cmd='B' → Undo=['A','B'], Redo=[]} 

procedure undoCommand (input/output Undo: Tstack, Redo: Tstack, output Cmd: character)
{I.S. : Undo tidak kosong, Redo terdefinisi}
{F.S. : elemen top Undo dipindah ke Redo, Cmd berisi elemen tersebut}
{Proses : pop dari Undo → Cmd, lalu push ke Redo}
{Contoh : Undo=['A','B','C'], Redo=[] → Undo=['A','B'], Redo=['C']} 

procedure redoCommand (input/output Undo: Tstack, Redo: Tstack, output Cmd: character)
{I.S. : Redo tidak kosong, Undo terdefinisi}
{F.S. : elemen top pada Redo dipindah ke Undo, Cmd berisi elemen tersebut}
{Proses : pop dari Redo → Cmd, lalu push ke Undo}
{Contoh : Undo=['A','B'], Redo=['C'] → Undo=['A','B','C'], Redo=[]} */

void addCommand (Tstack *Undo, Tstack *Redo, char Cmd)
{
    // push perintah baru ke Undo
    push(&(*Undo), Cmd);
    // kosongkan Redo karena ada perintah baru
    createStack(&(*Redo));
}
    
void UndoCommand (Tstack *Undo, Tstack *Redo, char *Cmd)
{
    if (!isEmptyStack(*Undo))
    {
        pop(&(*Undo), &(*Cmd));
        push(&(*Redo), *Cmd);
    }
}
    
void redoCommand(Tstack *Undo, Tstack *Redo, char *Cmd)
{
    if (!isEmptyStack(*Redo))
    {
        pop(&(*Redo), &(*Cmd));
        push(&(*Undo), *Cmd);
    }
}


/* 3. infixToPostfix */
/* function precedence(op: char) -> int
   {mengembalikan prioritas operator}*/
int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

/* procedure infixToPostfix(input expr: string, output postfix: string)
   {
   I.S. : expr berisi ekspresi infix valid (operand 0–9, operator + - * /, tanda kurung)
   F.S. : output string berupa postfix expression */
void infixToPostfix(const char *infix, int n, Tstack *out) {
    Tstack S;
    createStack(&S);
    createStack(out);

    char token, topOp;

    for (int i = 0; i < n; i++) {
        token = infix[i];

        if (token >= '0' && token <= '9') {
            push(out, token);
            push(out, ' ');
        }
        else if (token == '(') {
            push(&S, token);
        }
        else if (token == ')') {
            while (!isEmptyStack(S) && infoTop(S) != '(') {
                pop(&S, &topOp);
                push(out, topOp);
                push(out, ' ');
            }
            if (!isEmptyStack(S) && infoTop(S) == '(') {
                char dummy;
                pop(&S, &dummy);
            }
        }
        else if (token == '+' || token == '-' || token == '*' || token == '/') {
            while (!isEmptyStack(S) && precedence(infoTop(S)) >= precedence(token)) {
                pop(&S, &topOp);
                push(out, topOp);
                push(out, ' ');
            }
            push(&S, token);
        }
    }

    while (!isEmptyStack(S)) {
        pop(&S, &topOp);
        if (topOp != '(' && topOp != ')') {
            push(out, topOp);
            push(out, ' ');
        }
    }

     if (!isEmptyStack(*out) && infoTop(*out) == ' ') {
        char dummy;
        pop(out, &dummy);
    }
     return out;
}

/* 4. Evaluate Postfix*/
/*function evaluatePostfix (postfix:string, n:integer) → real
{I.S.: postfix terdefinisi, berisi operand (0–9) dan operator (+,-,*,/)}
{F.S.: Menghasilkan nilai hasil evaluasi postfix}
{Proses:
Baca token postfix satu per satu 
Jika token operand (angka) → push ke stack
Jika token operator → pop 2 operand (b, a), hitung a op b, lalu push hasilnya kembali ke stack 
Setelah semua token selesai, elemen terakhir di stack adalah hasil akhir}  
{Contoh:
  Postfix: "9 3 4 * 8 + 4 / -"
  langkah:
  Push 9
  Push 3
  Push 4
  '*' → pop 4,3 → 3*4=12 → push 12
  Push 8
  '+' → pop 8,12 → 12+8=20 → push 20
  Push 4
  '/' → pop 4,20 → 20/4=5 → push 5
  '-' → pop 5,9 → 9-5=4 → push 4
  Hasil akhir = 4 */
int evaluatePostfix(const char *expression, int n)
{
    // kamus lokal
    Tstack stack;
    int values[11] = {0};
    int i;
    char ch;
    char popped;
    int a;
    int b;
    int result;

    // algoritma
    i = 0;
    a = 0;
    b = 0;
    result = 0;

    createStack(&stack);

    for (i = 0; i < n; ++i)
    {
        ch = expression[i];

        if (ch != ' ')
        {

            if (ch >= '0' && ch <= '9')
            {
                if (isFullStack(stack))
                {
                    printf("Stack penuh saat memproses angka '%c'.\n", ch);
                    return 0; // was 0.0
                }

                push(&stack, ch);
                values[top(stack)] = (int)(ch - '0');
            }
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                if (top(stack) < 2)
                {
                    printf("Ekspresi postfix tidak valid. Operator '%c' kekurangan operand.\n", ch);
                    return 0;
                }

                int rightIndex = top(stack);
                b = values[rightIndex];
                pop(&stack, &popped);

                int leftIndex = top(stack);
                a = values[leftIndex];
                pop(&stack, &popped);

                switch (ch)
                {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    if (b == 0)
                    {
                        printf("Terjadi pembagian dengan nol.\n");
                        return 0;
                    }
                    result = a / b;
                    break;
                }

                push(&stack, '#');
                values[top(stack)] = result;
            }
            else
            {
                printf("Token '%c' tidak dikenali dalam ekspresi.\n", ch);
                return 0;
            }
        }
    }

    if (top(stack) != 1)
    {
        printf("Ekspresi postfix tidak valid. Operand tersisa %d.\n", top(stack));
        return 0;
    }

    return values[top(stack)];
}




