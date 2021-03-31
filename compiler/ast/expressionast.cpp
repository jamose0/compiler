#include "astnode.h"
#include "expressionast.h"

namespace Ast {

    const NodeType& UnaryExprNode::getType() const noexcept
    {
        return AstNode::getType();
    }

    const NodeType& BinaryExprNode::getType() const noexcept
    {
        return AstNode::getType();
    }

}
