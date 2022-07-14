#include "string_utils.hpp"

void StringManip::printInStr()
{
    std::cout << this->string_in;
}

void StringManip::CfileAndW()
{
    this->file_name.append(".replace");
    std::ofstream outfile (this->file_name);
    outfile << this->string_in;
    outfile.close();
}

void StringManip::searchStr()
{
    int count_subst = 0;
    size_t pos = 0;
    int len = this->sub.length();
    while ((pos = this->string_in.find(this->sub)) != std::string::npos)
    {
        this->string_in.erase(pos, len);
        this->string_in.insert(pos, this->to_sub);
        count_subst++;
    }
    if (count_subst == 0)
    {
        std::cout << "s1 not found." << std::endl;
        return;
    }

}

void StringManip::setSub(std::string sub)
{
    this->sub = sub;
}

void StringManip::setToSub(std::string to_sub)
{
    this->to_sub = to_sub;
}

void StringManip::getPath(const std::string& path)
{
    struct stat sb = {};
    std::string res;

    this->file_name = path;
    FILE* input_file = fopen(path.c_str(), "r");
    if (input_file == nullptr) {
        perror("erorr");
        return;
    }
    stat(path.c_str(), &sb);
    res.resize(sb.st_size);
    fread(const_cast<char*>(res.data()), sb.st_size, 1, input_file);
    fclose(input_file);
    this->string_in = res;
}
