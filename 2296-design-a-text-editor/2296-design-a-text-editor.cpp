class TextEditor {
public:
    TextEditor() {
        //before cursor string and after cursor string

    }
    
    void addText(string text) {
        before.insert(before.end(), text.begin(), text.end());
        
    }
    
    int deleteText(int k) {
        int tmp = min(k, int(before.size()));
        while (k-- && !before.empty()) {
            before.pop_back();
        }
        return tmp;
    }
    
    string cursorLeft(int k) {
        while (k-- && !before.empty()) {
            after.push_back(before.back());
            before.pop_back();
        }
        int len = min(10, int(before.length()));
        return before.substr(before.size() - len, len);
    }
    
    string cursorRight(int k) {
        while (k-- && !after.empty()) {
            before.push_back(after.back());
            after.pop_back();
        }
        int len = min(10, int(before.length()));
        return before.substr(before.size() - len, len);
        
    }
private:
    string before, after;
    
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */