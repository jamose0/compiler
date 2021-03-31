#ifndef AST_H
#define AST_H

#include "asttype.h"
#include "expressionast.h"
#include "astnode.h"


namespace Ast {
    class Ast
    {
    private:
        AstNode* m_root;
        
    public:
        Ast(AstNode& root)
            : m_root{&root}
        {
        }
    };
}

#endif
