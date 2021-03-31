#ifndef ASTNODE_H
#define ASTNODE_H

#include "asttype.h"
//#include "expressionast.h"

namespace Ast {

    /* AST base class */
    class AstNode
    {
    protected:
        NodeType m_type;
        
    public:
        AstNode(NodeType type) : m_type{type}
        {
        }

        virtual ~AstNode() {}
        
        virtual const NodeType &getType() const noexcept = 0;
    };
    
}

#endif
