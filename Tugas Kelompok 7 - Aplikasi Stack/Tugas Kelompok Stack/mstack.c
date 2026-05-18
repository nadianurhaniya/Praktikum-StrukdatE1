#include <stdio.h>
#include <string.h>
#include "stack.h"

/* Program   : mstack.c */
/* Deskripsi : driver ADT stack karakter */
/* Nama Kel  : Kelompok 7
            1. Muchammad Yuda Tri Ananda (24060124110142)
            2. Muhammad Kemal Faza (24060124120013)
            3. Nadia Azura Nurhaniya (24060124120019)
            4. Muhammad Zaidaan Ardiyansyah (24060124140200)
            5. Muhammad Farhan Abdul Azis (24060124140166)
/* Tanggal   : 21-09-2025 */
/***********************************/

int main()
{
    // kamus
    Tstack S;
    char e;

    // algoritma
    createStack(&S);
    printStack(S);

    // 1. isValidKurung
    char tes1[] = "({[]})";
    char tes2[] = "({[})";
    char tes3[] = "({[]}])";
    char tes4[] = "((()))";
    char tes5[] = "(())))";

    printf("%s is %s\n", tes1, isValidKurung(tes1, strlen(tes1)) ? "Valid" : "Not Valid");
    printf("%s is %s\n", tes2, isValidKurung(tes2, strlen(tes2)) ? "Valid" : "Not Valid");
    printf("%s is %s\n", tes3, isValidKurung(tes3, strlen(tes3)) ? "Valid" : "Not Valid");
    printf("%s is %s\n", tes4, isValidKurung(tes4, strlen(tes4)) ? "Valid" : "Not Valid");
    printf("%s is %s\n\n", tes5, isValidKurung(tes5, strlen(tes5)) ? "Valid" : "Not Valid");


    // 2. Undo Redo
    // Kamus Lokal
    Tstack Undo, Redo;
    char cmd;
    
    // Algoritma
    createStack(&Undo);
    createStack(&Redo);

    addCommand(&Undo, &Redo, 'a');
    addCommand(&Undo, &Redo, 'b');
    printStack(Undo);    // tampilkan isi stack Undo
    printStack(Redo);    // tampilkan isi stack Redo

    UndoCommand(&Undo, &Redo, &cmd);
    printf("undo: %c\n", cmd);

    redoCommand(&Undo, &Redo, &cmd);
    printf("redo: %c\n", cmd);


    // 3. Infix to Postfix
    char infix[] = "3+(4*5)-2";
    char hasilPostfix[100];
    infixToPostfix(infix, strlen(infix), hasilPostfix);
    printf("Infix  : %s\n", infix);
    printf("Postfix: %s\n\n", hasilPostfix);


    // 4. Evaluate Postfix
    // kamus lokal
    const char *input;
    int size;
    int result;

    // algoritma
    input = "9 3 4 * 8 + 4 / -";
    size = 17;

    result = evaluatePostfix(input, size);
    printf("Input: %s\n", input);
    printf("Output: %d\n", result);

    return 0;

}