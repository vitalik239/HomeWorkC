#include "lexer.h"
#include <iostream>

bool isarifm(char x)
{
    return (x == '+' || x == '-' || x == '/' || x == '*');
}

void Lexer::AddToken(TokenType type, const string& value, size_t pos)
{
    Tokens[Count].push_back(Token(type, value, pos));
}

void Lexer::GetWord()
{
    string value = "";
    int End = Pos;
    while (End < Code.size() && !isspace(Code[End]) && (isalnum(Code[End]) || isarifm(Code[End])))
        value += Code[End++];
       
    TokenType T;
    if (value == "var")
        T = tDECL;
    else if (value == "begin")
        T = tBEGIN;
    else if (value == "end")
        T = tEND;
    else if (value == "print")
        T = tPRINT;
    else if (value == "if")
        T = tIF;
    else if (value == "read")
        T = tREAD;
    else if (value != "")
        T = tIDENT;
    else cout << "HELLO  " << Code << " :" << Code[Pos] << ":" << endl;
    AddToken(T, value, Pos);
    Pos = End;
}

bool Lexer::GetCompar()
{
    string value = "";
    value += Code[Pos];
    value += Code[Pos + 1];
    if (value == "==" || value == ">=" || value == "<=" || value == "!=")
    {
        AddToken(tCOMP, value, Pos);
        Pos += 2;
    }
    else 
    {
        value = Code[Pos];
        if (value == ">" || value == "<")
            AddToken(tCOMP, value, Pos);
        else if (value == "=")
            AddToken(tEQ, value, Pos);
        else return false;
        Pos++;
    }
    return true;
}

void Lexer::Scan(const string & code) {
    Code = code;
    Pos = 0;
    if (Tokens.size() == Count)
        Tokens.resize(1 + Count * 1.7);
    while (Pos < Code.size())
    {
        while (Pos < Code.size() && isspace(Code[Pos]))
            Pos++;
        string value;
        if (Code[Pos] == '#')
        {
            AddToken(tCOMMENT, Code.substr(Pos), Pos);
            break;
        }
        if (Code[Pos] == ':')
        {
            AddToken(tBEGIN, ":", Pos++);     
            continue;
        }
        if (Pos < Code.size() && !GetCompar())
            GetWord();
    }
    Count++;
}

vector < vector <Token> > & Lexer::Get()
{
    return Tokens; 
}