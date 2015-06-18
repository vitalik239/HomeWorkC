#include <string>
#include <vector>

using namespace std;

enum TokenType { 
	tEQ,
	tCONST,
	tVAR,
	tDECL,
	tBEGIN,
	tEND,
	tCOMP,
	tIF, 
	tWHILE,
	tCOMMENT,
	tIDENT,
	tREAD,
	tPRINT 
};

struct Token
{
	TokenType Type;
	string Value;
	size_t Pos;
	Token(TokenType type, const string value, size_t pos) : Type(type), Value(value), Pos(pos) {}
};

class Lexer
{
	string Code;
	size_t Pos, Count;
	vector < vector <Token> > Tokens;

public:
	void Scan(const string& code);
	bool GetCompar();
	void GetWord();
	void AddToken(TokenType type, const string& value, size_t pos);
	vector < vector <Token> >& Get();
};