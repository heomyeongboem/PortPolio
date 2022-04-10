#define _CRT_SECURE_NO_WARNINGS
//
// ��:  Ű���� ��ū�� keyword table �� �̸� ����Ǿ� �ִ�. Ű���带 �ɺ����̺� ���������� �ʴ´�.

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define UNK 53     // �ν��� �� ���� ��ū�� ��Ÿ���� ��ū ��ȣ. ���� ��ū ��ȣ�� ?? �� �����־�� ��.
#define EOF_TOK 52 // token index of EOF token

int flag = 0;//�տ� \�� ������ 1 ������ 0
int flag_dq = 0;//�տ� "�� ������ 1 ������ 0 (ū ����ǥ)
int flag_sq = 0;//�տ� '�� ������ 1 ������ 0

int BQ_number = 0;

typedef struct tkt { // �ϳ��� ��ū�� ��Ÿ���� ����ü.
	int index;  // index : ��ū�� ������ ��Ÿ��, �� ��ū ��ȣ�� ����.
	char typ[16];
	char sub_kind[3];  // relop ��ū�� ��� �ٽ� �����ϴµ� �̿��.
						 // NUM ��ū�� ���� ��������("in") �Ǽ�������("do") ����.
	int sub_data; // ID ��ū�� �ɺ����̺�Ʈ�� ��ȣ, ���� ���� ���� ������.
	double rnum;  // �Ǽ��� ��� 
	char str[20]; // ��ū�� �����ϴ� ��Ʈ��.  // �Ƹ��� �� �ʵ�� �̿���� �ʴ� �� ����.
} tokentype;

typedef char oneword[50];

// keyword ���̺�  
// token index of "if" is 28. token index of other keywords are computed using this info.
char keywords[19][50] =
{ "if",    "else",  "while",  "do",   "for",    "include", "define", "typedef","struct","int",
   "char", "float", "double", "void", "return", "case",    "then",    "true",   "false" };
int total_keywords = 19; // ���߿� ���� ���.

//  symbol ���̺� 
typedef struct sym { oneword idstr; int attribute; } sym_ent;  // �ɺ����̺��� �� ��Ʈ���� ����.
sym_ent symtbl[500];
int total_ids = 0; // �ɺ����̺��� ������ ���� ��Ʈ�� ��ȣ

FILE* fp, * ofp;

int iswhitespace(char c) {
	if (c == ' ' || c == '\n' || c == '\t')
		return 1;
	else
		return 0;
}

int lookup_keyword_tbl(char* str) {
	int i;
	for (i = 0; i < total_keywords; i++)
		if (strcmp(keywords[i], str) == 0)
			return i;
	return -1;

}

int lookup_symtbl(char* str) {
	int i;
	for (i = 0; i < total_ids; i++)
		if (strcmp(symtbl[i].idstr, str) == 0)
			return i;
	return -1;
}
//*
//-------------------------------------------------------------
tokentype lexan() {
	//���� ���� ����

	int state = 0;
	char c;
	char buf[50];
	int bp = 0; // bp is buffer pointer(���� ���� ��ġ).

	int upper_n; // number ��ū���� �Ҽ��� �� �κ� �� ���� �κ��� ������.
	double fraction; // number ��ū���� �Ҽ��� �Ʒ� �κ��� ������.
	tokentype token;
	int idx, FCNT, sign, Enum;
	strcpy(token.typ, " ");
	while (1) {
		switch (state) {
		case 0: // �ʱ� ����. �� ��ū�� ù ���ڿ� ���� �۾� ���� �� ���� ���� ������.
			c = fgetc(fp);  // fgetc can be called even if fp is after the end of file.
							  // calling it again still returns EOF(-1) w/o invoking error.
			if (iswhitespace(c)) state = 0;  // this is white space.
			else if (isalpha(c)) { buf[bp] = c; bp++; buf[bp] = '\0'; state = 28; }
			else if (isdigit(c)) { buf[bp] = c; bp++; buf[bp] = '\0'; upper_n = c - '0'; state = 1; }
			else if (c == '<') state = 2;
			else if (c == '>') state = 32;
			else if (c == '=') state = 35;
			else if (c == '!') state = 38;
			else if (c == '+') state = 3;
			else if (c == '-') state = 4;
			else if (c == '*') state = 52;
			else if (c == '/') state = 8;
			else if (c == '\\') state = 53;
			else if (c == '%') state = 54;
			else if (c == '.') state = 55;
			else if (c == ',') state = 56;
			else if (c == '(') state = 57;
			else if (c == ')') state = 58;
			else if (c == '{') state = 59;
			else if (c == '}') state = 60;
			else if (c == '[') state = 61;
			else if (c == ']') state = 62;
			else if (c == ':') state = 63;
			else if (c == ';') state = 64;
			else if (c == '\"') { buf[bp] = c; bp++; buf[bp] = '\0'; state = 65; flag_dq = 1; }// flag_dq = 1 -> "�� �տ� ������ ���						
			else if (c == '\'') { buf[bp] = c; bp++; buf[bp] = '\0'; state = 66; flag_sq = 1; }// flag_sq = 1 -> '�� �տ� ������ ���
			else if (c == '#') state = 67;
			else if (c == '|') state = 68;
			else if (c == '&') state = 5;
			else if (c == EOF) state = 71;
			else {
				token.index = UNK; // �ν��� �� ���� ��ū���� ��Ÿ��.
				return token;
			}
			break;
		case 1: // NUM ��ū�� �Ҽ��� �� ���ڿ��� �޾� ���̴� ����.
			c = fgetc(fp);
			if (isdigit(c)) { buf[bp] = c; bp++; buf[bp] = '\0'; upper_n = 10 * upper_n + c - '0'; state = 1; }
			else if (c == '.') { buf[bp] = c; bp++; buf[bp] = '\0'; fraction = 0; FCNT = 0; state = 9; } // �Ҽ����� �������Ƿ� �Ǽ��� ó���ϴ� ���·� ��.
			else if (c == 'E') { buf[bp] = c; bp++; buf[bp] = '\0'; fraction = 0; state = 16; }  // E �� �ִ� exponent ó���η� ��.
			else state = 14;
			break;
		case 2: // ����ȣ���� < �� ���� ���� ó���� ����ϴ� ����.
			c = fgetc(fp);
			if (c == '=') state = 30;
			else state = 31;
			break;
		case 3: // ����ȣ���� + �� ���� ���� ó���� ����ϴ� ����.
			c = fgetc(fp);
			if (c == '=') state = 45;
			else if (c == '+') state = 47;
			else state = 46;
			break;
		case 4: // ����ȣ���� - �� ���� ���� ó���� ����ϴ� ����.
			c = fgetc(fp);
			if (c == '-') state = 48;
			else if (c == '=') state = 49;
			else if (c == '>') state = 51;
			else state = 50;
			break;
		case 5: // ����ȣ���� + �� ���� ���� ó���� ����ϴ� ����.
			c = fgetc(fp);
			if (c == '&') state = 6;
			else state = 7;
			break;
		case 6:
			token.index = 2; strcpy(token.sub_kind, "");		 strcpy(token.str, "&&");
			return token;
		case 7: // ��ū & �� �������ִ� ����.
			ungetc(c, fp);
			token.index = 13;
			return token;
		case 8:
			c = fgetc(fp);
			if (c == '/') state = 74;
			else if (c == '*') state = 75;
			else if (c == EOF) state = 71;
			else state = 72;
			break;
		case 9: // �Ǽ��� �Ҽ��� ���ϸ� �޾� ���̴� ����
			c = fgetc(fp);
			if (isdigit(c)) {
				buf[bp] = c; bp++; buf[bp] = '\0';
				FCNT++; fraction = fraction + (c - '0') / pow(10.0, FCNT); state = 23;
			}
			else if (c == 'E') { buf[bp] = c; bp++; buf[bp] = '\0'; state = 16; }
			else if (c == EOF)  state = 26;
			else if (iswhitespace(c)) state = 24;
			else state = 25;// goto unknown token state
			break;
		case 14: // ���� ���� ��ū�� �����ϴ� ����.
			ungetc(c, fp);
			token.index = 1; strcpy(token.sub_kind, "in"); // ���� ������ ��Ÿ��.
			token.sub_data = upper_n;
			strcpy(token.str, buf);
			strcpy(token.typ, "Number");
			return token;
		case 16:
			c = fgetc(fp);
			if (c == '+') { buf[bp] = c; bp++; buf[bp] = '\0'; sign = 1; state = 17; }
			else if (c == '-') { buf[bp] = c; bp++; buf[bp] = '\0'; sign = -1; state = 17; }
			else if (isdigit(c)) { buf[bp] = c; bp++; buf[bp] = '\0'; sign = 1; Enum = c - '0'; state = 18; }
			else  state = 25; // error! 		 
			break;
		case 17:
			c = fgetc(fp);
			if (isdigit(c)) { buf[bp] = c; bp++; buf[bp] = '\0'; Enum = c - '0'; state = 18; }
			else state = 25; // error!
			break;
		case 18:
			c = fgetc(fp);
			if (isdigit(c)) { buf[bp] = c; bp++;  buf[bp] = '\0'; Enum = Enum * 10 + c - '0'; state = 18; }
			else state = 19;
			break;
		case 19:
			ungetc(c, fp);
			token.index = 1; strcpy(token.sub_kind, "do"); // �Ǽ��� ��Ÿ��.
			token.rnum = (upper_n + fraction) * pow(10.0, sign * Enum);
			strcpy(token.str, buf);
			strcpy(token.typ, "Number");
			return token;

		case 23:
			c = fgetc(fp);
			if (isdigit(c)) {
				buf[bp] = c; bp++; buf[bp] = '\0';
				FCNT++; fraction = fraction + (c - '0') / pow(10.0, FCNT); state = 23;
			}
			else if (c == 'E') { buf[bp] = c; bp++; buf[bp] = '\0'; state = 16; }
			else state = 24;
			break;
		case 24:
			ungetc(c, fp);
			token.index = 1; strcpy(token.sub_kind, "do"); // �Ǽ��� ��Ÿ��.
			token.rnum = upper_n + fraction;
			strcpy(token.str, buf);
			strcpy(token.typ, "Number");
			return token;
		case 25:
			ungetc(c, fp);
			token.index = 53; // unknown token
			return token;
		case 26:  // do not call ungetc.
			token.index = 1; strcpy(token.sub_kind, "do"); // �Ǽ��� ��Ÿ��.
			token.rnum = upper_n + fraction;
			strcpy(token.str, buf);
			strcpy(token.typ, "Number");
			return token;
		case 28:
			c = fgetc(fp);
			if (isalpha(c) || isdigit(c) || c == '_') { buf[bp] = c; bp++; buf[bp] = '\0'; state = 28; }
			else	 state = 29;
			break;
		case 29: // id �� keyword 
			ungetc(c, fp);
			strcpy(token.str, buf);
			idx = lookup_keyword_tbl(buf); // -1 if not exist.
			if (idx >= 0) { token.index = 31 + idx; strcpy(token.typ, "Keyword"); return token; }  // Note: first keyword has token index 30.
			// reaches here if it is not a keyword.
			idx = lookup_symtbl(buf); // -1 if not exist.
			if (idx >= 0) { token.index = 0; token.sub_data = idx; strcpy(token.typ, "Identifier"); return token; }
			// reaches here if it is not in symbol table.
			strcpy(symtbl[total_ids].idstr, buf); total_ids++;
			token.index = 0; // ID ��ū���� ��Ÿ��.
			token.sub_data = total_ids - 1; // �� ID �� ��� �ִ� �ɺ����̺� ��Ʈ�� ��ȣ.
			strcpy(token.typ, "Identifier");
			return token;
		case 30:
			token.index = 2; strcpy(token.sub_kind, "LE"); strcpy(token.str, "<=");
			strcpy(token.typ, "ROP");
			return token;
		case 31:
			ungetc(c, fp);
			token.index = 2; strcpy(token.sub_kind, "LT"); strcpy(token.str, "<");
			strcpy(token.typ, "ROP");
			return token;
		case 32:
			c = fgetc(fp);
			if (c == '=') state = 33;
			else state = 34;
			break;
		case 33:
			token.index = 2; strcpy(token.sub_kind, "GE");	strcpy(token.str, ">=");
			strcpy(token.typ, "ROP");
			return token;
		case 34:
			ungetc(c, fp);
			token.index = 2; strcpy(token.sub_kind, "GT"); strcpy(token.str, ">");
			strcpy(token.typ, "ROP");
			return token;
		case 35: // ���� = �� ���� ���� ó���� ����ϴ� ����.
			c = fgetc(fp);
			if (c == '=') state = 36;
			else state = 37;
			break;
		case 36: // ��ū == �� ���� ó���� �����ϴ� ����.
			token.index = 2; strcpy(token.sub_kind, "EQ");	strcpy(token.str, "==");
			strcpy(token.typ, "ROP");
			return token;
		case 37: // ��ū > �� ���� ó���� �����ϴ� ����.
			ungetc(c, fp);
			token.index = 8; strcpy(token.str, "=");
			strcpy(token.typ, "Symbol");
			return token;
		case 38:
			c = fgetc(fp);
			if (c == '=') state = 39;
			else state = 40;
			break;
		case 39:
			token.index = 2; strcpy(token.sub_kind, "NE");	 strcpy(token.str, "!=");
			strcpy(token.typ, "ROP");
			return token;
		case 40:
			ungetc(c, fp);
			token.index = 10;  strcpy(token.str, "!"); // NOT		
			strcpy(token.typ, "ROP");
			return token;
		case 45:
			token.index = 16; 		 strcpy(token.str, "+=");
			return token;
		case 46:
			ungetc(c, fp);
			token.index = 3;  strcpy(token.str, "+");
			strcpy(token.typ, "Symbol");
			return token;
		case 47:
			token.index = 14;		 strcpy(token.str, "++");
			strcpy(token.typ, "Symbol");
			return token;
		case 48:
			token.index = 15;		 strcpy(token.str, "--");
			strcpy(token.typ, "Symbol");
			return token;
		case 49:
			ungetc(c, fp);
			token.index = 17;  strcpy(token.str, "-=");
			strcpy(token.typ, "Symbol");
			return token;
		case 50:
			ungetc(c, fp);
			token.index = 4;		 strcpy(token.str, "-");
			strcpy(token.typ, "Symbol");
			return token;
		case 51:
			token.index = 9;		 strcpy(token.str, "->");
			strcpy(token.typ, "Symbol");
			return token;
		case 52:
			token.index = 5;		 strcpy(token.str, "*");
			strcpy(token.typ, "Symbol");
			return token;
		case 53:
			token.index = 30;		 strcpy(token.str, "\\");
			strcpy(token.typ, "Symbol");
			return token;
		case 54:
			token.index = 7;		 strcpy(token.str, "%");
			strcpy(token.typ, "Symbol");
			return token;
		case 55:
			token.index = 11;		 strcpy(token.str, ".");
			strcpy(token.typ, "Symbol");
			return token;
		case 56:
			token.index = 12;		 strcpy(token.str, ",");
			strcpy(token.typ, "Symbol");
			return token;
		case 57:
			token.index = 18;		 strcpy(token.str, "(");
			strcpy(token.typ, "Symbol");
			return token;
		case 58:
			token.index = 19;		 strcpy(token.str, ")");
			strcpy(token.typ, "Symbol");
			return token;
		case 59:
			token.index = 20;		 strcpy(token.str, "{");
			strcpy(token.typ, "Symbol");
			return token;
		case 60:
			token.index = 21;		 strcpy(token.str, "}");
			strcpy(token.typ, "Symbol");
			return token;
		case 61:
			token.index = 22;		 strcpy(token.str, "[");
			strcpy(token.typ, "Symbol");
			return token;
		case 62:
			token.index = 23;		 strcpy(token.str, "]");
			strcpy(token.typ, "Symbol");
			return token;
		case 63:
			token.index = 24;		 strcpy(token.str, ":");
			strcpy(token.typ, "Symbol");
			return token;
		case 64:
			token.index = 25;		 strcpy(token.str, ";");
			strcpy(token.typ, "Symbol");
			return token;
		case 65://"" 
			c = fgetc(fp);
			if (c == '"' && flag_dq == 1) { flag_dq = 0;  buf[bp] = c; bp++; buf[bp] = '\0'; state = 100; }//"�� �Դµ� flag_dq =1�̴�. -> �տ� "�� �ִ� ���¿��� "�� �� �Դ�. -> ���ڿ� ��� ������ �ǹ�
			else if (c == EOF) { state = 100; }
			else if (flag == 0) {
				if (c == '\\') { buf[bp] = c; bp++; buf[bp] = '\0'; state = 65; flag = 1; }//\�� ����ħ => flag = 1 ��ġ
				else { buf[bp] = c; bp++; buf[bp] = '\0'; state = 65; }//other �κ�
			}
			// �� ���쿡 \�� ����ִ�.
			else {
				flag = 0;//���⸦ ��ģ �ٷ� �������´� escape sequence�� �ƴϹǷ� flag =0 ���� ó�����ش�. 

				switch (c) {

				case 'r'://�ƽ�Ű �ڵ�� ó��
					buf[bp - 1] = '\'';

					buf[bp] = '13';

					bp++;
					buf[bp] = '\'';

					bp++;
					buf[bp] = '\0';
					state = 65;

					break;

				case 'n'://�ƽ�Ű �ڵ�� ó��				
					buf[bp - 1] = '\'';

					buf[bp] = '10';

					bp++;
					buf[bp] = '\'';

					bp++;
					buf[bp] = '\0';

					state = 65;

					break;

				case 't'://�ƽ�Ű �ڵ�� ó��

					buf[bp - 1] = '\'';

					buf[bp] = '9';

					bp++;

					buf[bp] = '\'';

					bp++;

					buf[bp] = '\0';

					state = 65;

					break;


				case '0'://�ƽ�Ű �ڵ�� ó��

					buf[bp - 1] = '\'';

					buf[bp] = '0';

					bp++;
					buf[bp] = '\'';

					bp++;
					buf[bp] = '\0';

					state = 65;

					break;

				case '"'://��� �ƽ�Ű �ڵ尡 �ƴ� ���ڷ� ó�� =>�ٽ�
					buf[bp - 1] = c;
					state = 65;
					break;

				default://\������ escape ���ڰ� �ƴϸ� \�� ���� ������ش�.
					buf[bp] = c; bp++; buf[bp] = '\0';
					state = 65;
					break;
				}
			}
			break;
		case 100: // ���Ƿ� ���� ģ���� case 29���� ��� ��������� ��κ��� case���� �� �۵������� " �� ģ�����״� �����ϰԵ� ungetc �Լ��� ����ϹǷ� "�� �ѹ� �� ������ �Ѵ�. �׷��Ƿ� �긦 ����� �׷� �һ�縦 �����ش�.
			//ungetc(c, fp);
			strcpy(token.str, buf);
			idx = lookup_keyword_tbl(buf); // -1 if not exist.
			if (idx >= 0) { token.index = 31 + idx; strcpy(token.typ, "Keyword"); return token; }  // Note: first keyword has token index 30.
			// reaches here if it is not a keyword.
			idx = lookup_symtbl(buf); // -1 if not exist.
			if (idx >= 0) { token.index = 0; token.sub_data = idx; strcpy(token.typ, "Identifier"); return token; }
			// reaches here if it is not in symbol table.
			strcpy(symtbl[total_ids].idstr, buf); total_ids++;
			token.index = 0; // ID ��ū���� ��Ÿ��.
			token.sub_data = total_ids - 1; // �� ID �� ��� �ִ� �ɺ����̺� ��Ʈ�� ��ȣ.
			strcpy(token.typ, "Identifier");
			return token;
		case 66:
			c = fgetc(fp);
			// �� ���쿡 \�� ������� �ʴ�. 
			if (c == '\'' && flag_sq == 1) { flag_sq = 0;  buf[bp] = c; bp++; buf[bp] = '\0'; state = 100; }//'�� �Դµ� flag_sq =1�̴�. -> �տ� '�� �ִ� ���¿��� '�� �� �Դ�. -> ���� ��� ������ �ǹ�
			else if (c == EOF) { state = 100; }
			else if (flag == 0) {
				if (c == '\\') { buf[bp] = c; bp++; buf[bp] = '\0'; state = 66; }//\�� ����ħ
				else { buf[bp] = c; bp++; buf[bp] = '\0'; state = 66; }//other �κ�
			}
			// �� ���쿡 \�� ����ִ�.
			else {
				flag = 0;//���⸦ ��ģ �ٷ� �������´� escape sequence�� �ƴϹǷ� flag =0 ���� ó�����ش�. 

				switch (c) {
				case 'r'://�ƽ�Ű �ڵ�� ó��
					buf[bp - 1] = '\'';

					buf[bp] = '13';

					bp++;
					buf[bp] = '\'';

					bp++;
					buf[bp] = '\0';
					state = 66;

					break;

				case 'n'://�ƽ�Ű �ڵ�� ó��				
					buf[bp - 1] = '\'';

					buf[bp] = '10';

					bp++;
					buf[bp] = '\'';

					bp++;
					buf[bp] = '\0';

					state = 66;

					break;

				case 't'://�ƽ�Ű �ڵ�� ó��

					buf[bp - 1] = '\'';

					buf[bp] = '9';

					bp++;

					buf[bp] = '\'';

					bp++;

					buf[bp] = '\0';

					state = 66;

					break;


				case '0'://�ƽ�Ű �ڵ�� ó��

					buf[bp - 1] = '\'';

					buf[bp] = '0';

					bp++;
					buf[bp] = '\'';

					bp++;
					buf[bp] = '\0';

					state = 66;

					break;

				case '\''://��� �ƽ�Ű �ڵ尡 �ƴ� ���ڷ� ó�� =>�ٽ�
					buf[bp - 1] = c;
					state = 66;
					break;

				default://\������ escape ���ڰ� �ƴϸ� \�� ���� ������ش�.
					buf[bp] = c; bp++; buf[bp] = '\0';
					state = 66;
					break;

				}


			}

			break;

		case 67:
			token.index = 28;		 strcpy(token.str, "#");
			strcpy(token.typ, "Symbol");
			return token;
		case 68:
			c = fgetc(fp);
			if (c == '|') 	state = 69;
			else 	 state = 70;
			break;
		case 69:
			token.index = 2;	strcpy(token.sub_kind, "OR");	 strcpy(token.str, "||");
			strcpy(token.typ, "Symbol");
			return token;
		case 70:
			ungetc(c, fp);
			token.index = 29;	 strcpy(token.str, "|");
			strcpy(token.typ, "Symbol");
			return token;
		case 71:
			token.index = EOF_TOK; strcpy(token.str, "EOF");
			strcpy(token.typ, "EOF");
			return token;
		case 72:
			ungetc(c, fp);
			token.index = 6; strcpy(token.str, "/");
			return token;
		case 73:
			token.index = 6; strcpy(token.str, "/");
			strcpy(token.typ, "Symbol");
			return token;
		case 74:
			c = fgetc(fp);
			if (c == '\n') state = 0;
			else if (c == EOF) state = 71;
			else state = 74;
			break;
		case 75:
			c = fgetc(fp);
			if (c == '*') state = 76;
			else if (c == EOF) state = 71;
			else state = 75;
			break;
		case 76:
			c = fgetc(fp);
			if (c == '/') state = 0;
			else if (c == EOF) state = 71;
			else state = 75;
			break;
		default: printf("Unrecognizable token! Stop generating tokens.\n");
			token.index = UNK; strcpy(token.str, "UNK");
			return token;
		} // switch
	} //while
}

//--------------------------------------
void print_token(tokentype a_tok, FILE* ofp) {
	fprintf(ofp, "%s\tToken_idx: %d,  %s ", a_tok.str, a_tok.index, a_tok.typ); // ��ū ���� ��� (������ ��Ʈ������ ��ü��)
	printf("%s\tToken_idx: %d,  %s ", a_tok.str, a_tok.index, a_tok.typ);

	if (a_tok.index == 1) { // this is number token.
		if (strcmp(a_tok.sub_kind, "in") == 0) {
			fprintf(ofp, "   integer  Val= %d", a_tok.sub_data); // ������ū��.
			printf("   integer  Val= %d", a_tok.sub_data);
		}
		else if (strcmp(a_tok.sub_kind, "do") == 0) {
			fprintf(ofp, "   double  Val= %10.7f", a_tok.rnum); // �Ǽ� ��ū��.
			printf("   double  Val= %10.7f", a_tok.rnum);
		}
	}
	else if (a_tok.index == 0) {
		fprintf(ofp, "  Symtbl_idx = %5d", a_tok.sub_data); // id �� �ɺ����̺� ��Ʈ��.
		printf("  Symtbl_idx = %5d", a_tok.sub_data);
	}
	else;
	fprintf(ofp, "\n");
	printf("\n");

	fflush(ofp);
}
//*/
//-------------------------------------------------------------
void main(void) {
	tokentype a_tok;
	char source_file[30] = "sourcefile.txt";
	char output_file[30] = "outputfile.txt";
	char c;
	int i;

	fp = fopen(source_file, "r"); // �Է� �ҽ� ȭ��
	if (!fp) { printf("file open error of file = %s", source_file); return; }
	ofp = fopen(output_file, "w"); // ��� ȭ��
	if (!ofp) { printf("file open error of file = %s", output_file); return; }

	while (1) {
		a_tok = lexan();
		if (a_tok.index == EOF_TOK) // EOF ��ū�̸�,
			break; // there will be no more token. so exit.
		else if (a_tok.index == UNK)
			break; // terminate token generation since wrong token has appeared.
		else
			print_token(a_tok, ofp);
	}
	fclose(fp);
	fclose(ofp);
	printf("Program ends with success.\n\n");
	return;
} // main

