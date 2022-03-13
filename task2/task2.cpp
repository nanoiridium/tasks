#include <iostream>
#include <vector>

std::string NextPermutationAlgorithm(std::string w)  
{
    int l = w.length();
    std::vector<char> bytes(w.begin(), w.end());
    bytes.push_back('\0');
    char *b = &bytes[0];
	std::string r = "\0";

	for (int i = l - 1; i > 0; i--)
    {
		if (b[i-1] < b[i]) 
        {
			int pivot = i;
			for (int j = pivot; j < l; j++)
            {
				if (w[j] <= b[pivot] && b[i-1] < b[j]) 
                {
					pivot = j;
				}
			}

            auto tmp = b[i-1]; b[i-1] = b[pivot]; b[pivot] = tmp;

			for (int j = l-1; i < j; i++, j--) 
            {
                auto tmp = b[i]; b[i] = b[j]; b[j] = tmp;
			}

			r = b;
			break;
		}
	}

	return r;
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