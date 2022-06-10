#include "cmpslib19.h"
#include "easylogging++.h"

template <class T>
class  demo
{
    private:
        T data;

    public:
        T getData()
        {
            return data;
        }

        void setData(T val)
        {
            data = val;
        }

        friend std::ostream& operator << (std::ostream& os,  demo& s)
        {
            os << "  size of (data) = " << sizeof(s.getData()) << endl;
            os << "  data is of type " << GetClassName(s.getData()) << endl;
            os << "  data contains: " << s.getData() << endl;
            return os;
        }
};
