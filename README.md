# **compiler-miniLisp**
## **簡介**
```
大三compiler課的final project，目標是要做出一個miniLisp
的編譯器，方法不限。我使用的方法是先將miniLisp code透過
Lex/yacc轉成C++ code，再使用g++編譯執行。
```
## **Mini-LISP Overview**  
```
LISP is an ancient programming language based on 
S-expressions and lambda calculus. All operations in 
Mini-LISP are written in parenthesized prefix 
notation. For example, a simple mathematical formula 
“(1 + 2) * 3” written in Mini-LISP is:
(* (+ 1 2) 3)
As a simplified language, Mini-LISP has only three
 types (Boolean, number and function) and a few 
 operations.
```
## **How to run**
```
1.在Linux環境下開啟終端機

2.把Mini-Lisp code 放在input.txt

3. ./build.sh 編譯

4. ./run.sh 執行
```
