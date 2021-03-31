#include "astnode.h"
#include "token.h"

namespace Ast {

    /* Watch out for weird lifetime errors */

    class ExprNode : public AstNode
    {
    };

    class UnaryExprNode : public ExprNode
    {
    private:
        ExprNode* m_rhs;

        TokenType m_unaryOperator;

    public:
        UnaryExprNode(ExprNode &expr, TokenType op)
            : m_rhs{&expr}, m_unaryOperator{op}
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
        BinaryExprNode(ExprNode &lhs, ExprNode &rhs, TokenType op)
            : m_lhs{&lhs}, m_rhs{&rhs}, m_binaryOperator{op}
        {
        }
    };

}
