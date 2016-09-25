#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Trie
{
    private:
        int words;
        int prefixes;
        Trie *edges[26];
    public:
        Trie()
        {
            words = 0;
            prefixes = 0;
            for(int i=0;i<26;i++)
            {
                edges[i] = NULL;
            }
        }

        void show()
        {
            cout<<"Words: "<<words<<endl;
            cout<<"Prefixes: "<<prefixes<<endl;
            cout<<"Edges: ";
            for(int i=0; i<26; i++)
                cout<<edges[i]<<" ";
        }

        void addWord(string word)
        {
            if(word.empty()) //If all the characters from the word have been removed, it ends here.
                words++;
            else    //This is the prefix of some other word.
            {
                prefixes++;
                char f = word[0];
                int index = (int) f - 97;
                if(edges[index] == NULL)
                {
                    edges[index] = new Trie;
                }
                word.erase(0,1); //Removes the first character from the word.
                edges[index]->addWord(word);
            }
        }

        int countWords(string word)
        {
            if(word.empty())
                return words;
            char f = word[0];
            int index = (int) f - 97;
            if(edges[index] == NULL)
                return 0;
            else
            {
                word.erase(0,1);
                return edges[index]->countWords(word);
            }

        }

        int countPrefixes(string prefix)
        {
            if(prefix.empty())
                return prefixes;
            char f = prefix[0];
            int index = (int) f - 97;
            if(edges[index] == NULL)
                return 0;
            else
            {
                prefix.erase(0,1);
                return edges[index]->countPrefixes(prefix);
            }

        }

};

int main()
{
    Trie t;
    t.addWord("hello");
    t.addWord("hell");
    t.addWord("hedd");
    t.addWord("dummybaba");
    t.addWord("chipsu");
    cout<<t.countWords("hell")<<" ";
    cout<<t.countPrefixes("he");
    return 0;
}
