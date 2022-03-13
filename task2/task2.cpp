#include <iostream>
#include <vector>

void swap(char &in1, char &in2)
{
    auto tmp = in1; 
    in1 = in2; 
    in2 = tmp;
}

std::string NextPermutationAlgorithm(std::string in)  
{
    int strLen = in.length();
    std::vector<char> bytes(in.begin(), in.end());
    bytes.push_back('\0');
    char *handler = &bytes[0];

    int index = -1;
	for (int i = strLen - 1; i > 0; i--)
    {
		if (handler[i-1] >= handler[i]) 
        {
            continue;
        }
        index = i;
        break;
    }

    if (index < 0)
    {
        return std::string("\0");
    }


	int pivot = index;
	for (int j = pivot; j < strLen; j++)
    {
		if (in[j] <= handler[pivot] && handler[index-1] < handler[j]) 
        {
			pivot = j;
		}
	}

    swap(handler[index-1], handler[pivot]);

	for (int j = strLen-1; index < j; index++, j--) 
    {
        swap(handler[index], handler[j]);
	}

	return std::string(handler);
}

int main()
{

    std::string abc = "abc";
    char sign[3];

    std::cin >> sign[0] >> sign[1] >> sign[2]; //ab, ac, bc

    while(abc[0] != '\0')
    {
        std::cout << abc << std::endl;
        abc = NextPermutationAlgorithm(abc);
    } 

    return 0;
}