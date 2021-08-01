# CmdOptionParser

CmdOptionParser is options parser for command line.  

## Usage
```c++
std::vector<std::pair<std::string, bool> > option_key_list = { std::make_pair("string", false)}; 
auto i = std::make_unique<CmdOption>(argv, argc, "--",  option_key_list);
```

option_key_list is option key list; that list is using std::pair<std::string, bool>.  
first is key. second is whether exists value, when that value is true is meaning that option is pair of key and value, when false is meaning that option is not pair.  
  
then run above
```c++
auto count = i.get()->DetectOptions();
```

DetectOptions method is search option from string list using arbitrary option list.  
That method is if found value then append to option_list of private member and return found value count.   

```c++  
auto result = i.get()->GetOptions();
```  
GetOptions method is return std::vector<std::pair<std::string, std::string> >.  