class Spreadsheet {
    unordered_map<string, int> cells;
    public:
        Spreadsheet(int rows) {}
        void setCell(const string& cell, int value) {
            cells[cell] = value;
        }

        void resetCell(const string& cell) {
            cells[cell] = 0;
        }

        int getValue(const string& expr) {
            string s = expr.substr(1);

            size_t pos = s.find('+');
            if (pos != string::npos) {
                string left = s.substr(0, pos);
                string right = s.substr(pos + 1);

                auto getVal = [&](const string& x) {
                    if (isalpha(x[0])) return cells[x];
                    return stoi(x);
                };

                return getVal(left) + getVal(right);
            }
            return 0;
        }
};
