#include "DataFilter.h"
#include "DataFilterHelperFunctions.cpp"

//Takes a .csv file and creates a new clean one
void filterData (string fileName){
	vector <string> toBeFiltered = readFileIntoVector(fileName);

	toBeFiltered = removeIncompleteData(toBeFiltered);
	toBeFiltered = removeGarbledData(toBeFiltered);
	toBeFiltered = removeRepeatedData(toBeFiltered);

	writeVectorIntoFile("CleanedData.csv", toBeFiltered);
}

//Removes data points where there is missing data
vector <string> removeIncompleteData(vector <string> strVec){
	vector <string> result;
	for (string s: strVec){
		if (enoughCommas(s)){
			result.push_back(s);
		}
	}
	return result;
}

//Removes data points where data is corrupted
vector <string> removeGarbledData(vector <string> strVec){
	vector <string> result;
	for (string s: strVec){
		if (properNumbers(s) && properData(s)){
			result.push_back(s);
		}
	}
	return result;
}

//Removes repeated data
vector <string> removeRepeatedData(vector <string> strVec){
	vector <string> result;
	for (int i = 1; i < strVec.size(); i++){
		if (!(strVec[i] == strVec[i-1])){
			result.push_back(strVec[i]);
		}
	}
	return result;
}

int main(){
	filterData("RotaSat ESA Telemetry Data.csv");
    return 0;
}
