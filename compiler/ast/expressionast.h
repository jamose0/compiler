#include "astnode.h"
#include "token.h"

namespace Ast {

    class ExprNode : public AstNode
    {
    };

    class UnaryExprNode : public ExprNode
    {
    private:
        ExprNode* m_rhs;

        TokenType m_unaryOperator;

    public:
        UnaryExprNode(TokenType op) : m_unaryOperator{op}
        {
        }
    };

    class BinaryExprNode : public ExprNode
    {
    private:
        ExprNode* m_lhs;
        ExprNode* m_rhs;

        TokenType m_binaryOperator;
        
    public:
        BinaryExprNode(TokenType op)
            : m_binaryOperator{op}
        {
        }
    };

}
