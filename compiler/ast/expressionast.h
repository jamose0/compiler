#include "astnode.h"
#include "token.h"

namespace Ast {

    class ExprAst : public AstNode
    {
    };

    class BinaryExprAst : public ExprAst
    {
    private:
        ExprAst* m_lhs;
        ExprAst* m_rhs;

        TokenType m_binaryOperator;
        
    public:
        BinaryExprAst(TokenType op)
            : m_binaryOperator{op}
        {
        }
    };

}
