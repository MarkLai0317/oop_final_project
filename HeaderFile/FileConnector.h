#include <fstream>
#include <map>
#include <vector>

class FileConnector{

    public:

        FileConnector(std::string name);

        ~FileConnector();

        // return 哪一行
        std::vector<int> search(std::string from, std::string target);

        //找到那行的那個位置修改其值，如果找不到要回傳錯誤訊息
        void update(std::string from_property, std::string which_is, std::string from_col, std::string change_to);

        //vector裡面要裝有 id name price category
        void append(std::vector<std::string>);

    private:

        void readCsv();
        void write();

        std::ifstream input_file;
        std::ofstream output_file; 
        std::string file_name;
        std::vector<std::vector<std::string> > table;
        std::map<std::string, int> column;

};
