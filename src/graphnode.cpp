#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    // warm-up task, Remove Initial Seg fault.
    //delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

// Task 4: change to unique ptr.
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{   
    //using std::move to move unique ptr.
    //push_back()` creates a copy of the element you are adding to it, 
    //and hence you get the error that you are trying to use copy assignment 
    //on a `unique_ptr`, which is not allowed. Hence, you need to transfer 
    //ownership from the pointer passed into the function to the `unique_ptr` in the `vector` container.
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
//Task 5: change argument type due to need chatbot instance in LoadAnswerGraphFromFile.
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    _chatBot = chatbot;
    //Task 5: _chatbot not equal to ptr anymore.
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(_chatBot);
    //Task 5: not ptr anymore, due to LoadAnswerGraphFromFile's new instance.
    //_chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}