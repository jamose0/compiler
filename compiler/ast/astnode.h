#ifndef ASTNODE_H
#define ASTNODE_H

#include "ast.h"

namespace Ast {

    /* AST base class */
    class AstNode
    {
    public:
        
        virtual const NodeType &getType() const noexcept  = 0;
    };
    
}

#endif
