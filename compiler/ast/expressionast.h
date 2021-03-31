#include "astnode.h"
#include "token.h"

namespace Ast {

    /* Watch out for weird lifetime errors */

    class ExprNode : public AstNode
    {
    public:
        ExprNode() = default;
        ExprNode(NodeType type)
            : AstNode(type)
        {
        }
    };

    class UnaryExprNode : public ExprNode
    {
    private:
        ExprNode* m_rhs;

        TokenType m_unaryOperator;

    public:
        UnaryExprNode(ExprNode &expr, TokenType op)
            : ExprNode(NodeType::UNARY_EXPR), m_rhs{&expr}, m_unaryOperator{op}
        {
        }

        virtual const NodeType &getType() const noexcept;
    };

    class BinaryExprNode : public ExprNode
    {
    private:
        ExprNode* m_lhs;
        ExprNode* m_rhs;

        TokenType m_binaryOperator;
        
    public:
        BinaryExprNode(ExprNode &lhs, ExprNode &rhs, TokenType op)
            : ExprNode(NodeType::BINARY_EXPR), m_lhs{&lhs}, m_rhs{&rhs},
              m_binaryOperator{op}
        {
        }

        virtual const NodeType &getType() const noexcept;
    };

}
