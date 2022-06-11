#include "dummyHead.h"
struct Tag{
    string tagName;
    unordered_map<string, string> attributes;
    unordered_map<string, shared_ptr<Tag>> childTags;
};

vector<string> splitStringWithMultiDelimiters(string str, string delimiter)
{
    std::stringstream stringStream(str);
    std::string line;
    vector<string> strings;
    while (std::getline(stringStream, line))
    {
        std::size_t prev = 0, pos;
        while ((pos = line.find_first_of(delimiter, prev)) != std::string::npos)
        {
            if (pos > prev)
                strings.push_back(line.substr(prev, pos - prev));
            prev = pos + 1;
        }
        if (prev < line.length())
            strings.push_back(line.substr(prev, std::string::npos));
    }
    return strings;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int numOfHTML, numOfQueuy;
    cout << "Enter numOfHTML & numOfQueuy: ";
    cin >> numOfHTML >> numOfQueuy;
    stack<shared_ptr<Tag>> st;
    shared_ptr<Tag> outTag = nullptr;
    
    // Reading html
    for(int k = 0; k < numOfHTML; ++k){
        shared_ptr<Tag> tag = make_shared<Tag>();
        string tagHead;
        cin >> tagHead;
        if(tagHead.substr(4) == "<tag"){
            tag->tagName = tagHead.substr(1,tagHead.size()-2);
            string key, equal, value;
            cout << "Enter key = value";
            while(cin >> key >> equal >> value){
                cout << "Enter key = value";
                tag->attributes[key] = (value.back() == '>') ? value.substr(value.length() - 1) : value;
                if(value.back() == '>')
                    break;
            }
            if(!st.empty())
                st.top()->childTags[tag->tagName] = tag;
            st.push(tag);
        }
        else if(tagHead.substr(5) == "</tag"){
            outTag = st.top();
            st.pop();
        }
    }
    
    // Reading queuy
    for(int k = 0; k < numOfQueuy; ++k){
        shared_ptr<Tag> currentSearchTag = outTag;
        string query;
        cin >> query;
        vector<string> queryOrder = splitStringWithMultiDelimiters(query, ".~");
        string att = queryOrder.back();
        queryOrder.pop_back();
        bool found = true;
        // go to the target tag
        for(const string& q : queryOrder){
            if(currentSearchTag->tagName == q){
                break;
            }   
            else if(currentSearchTag->childTags.count(q))
                currentSearchTag = currentSearchTag->childTags[q];
            else {
                found = false;
                break;
            }
        }
        if(!found)
            cout << "Not Found!" << endl;
        else {
            if(currentSearchTag->attributes.count(att))
                cout << currentSearchTag->attributes[att] << endl;
            else
                cout << "Not Found!" << endl;
        }
    }
    
    return 0;
}