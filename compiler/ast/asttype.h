#ifndef ASTTYPE_H
#define ASTTYPE_H


//#include "expressionast.h"

namespace Ast {

    enum class NodeType
    {
        BINARY_EXPR,
        UNARY_EXPR,
            
    };
    /*
    class Ast
    {
    private:
        ExprNode* m_root;

    public:
        Ast(ExprNode &root)
            : m_root{&root}
        {
        }
        };*/
}

#endif
