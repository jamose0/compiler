#include "astnode.h"

namespace Ast {
    const NodeType& AstNode::getType() const noexcept
    {
        return m_type;
    }
}
