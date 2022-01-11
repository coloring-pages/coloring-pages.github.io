#include<bits/stdc++.h>
using namespace std;

string mainkey, subkey, desc, tag; //tag = [mainkey, parkey]; parkey chi nen la 1 word
int numOfImages;
string src; //Source of quote
string filename; //Dạng websiteUrl+2015-02-26-flake-it-till-you-make-it.md
string day, month, year;
string websiteUrl = "https://coloring-pages.github.io/";
string postUrl; //Dang https://hoanghabc.github.io/2020/02/26/flake-it-till-you-make-it.html

string imageFileName; //Dang main-key-1.jpg
string ImageUrl; //dang: websiteUrl+"/"+parkey+"/"+imageFileName

string prePost[5]={
    "This post is about ",
    "Download all these collection of ",
    "Make it your own and feel free to share this ",
    "This is a special collection of ",
    "Free and printable avaiable for you to download"
};

string ads = "<script async src=\"https://pagead2.googlesyndication.com/pagead/js/adsbygoogle.js?client=ca-pub-6753140515841889\" crossorigin=\"anonymous\"></script> <ins class=\"adsbygoogle\" style=\"display:block\" data-ad-format=\"autorelaxed\" data-ad-client=\"ca-pub-6753140515841889\" data-ad-slot=\"5405745125\"></ins><script>(adsbygoogle = window.adsbygoogle || []).push({}); </script>";
string int2str(int n){
    stringstream ss;
    ss << n;
    string str = ss.str();  
    return str;
}

void getday(){
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);

    int d = aTime->tm_mday;
    int m = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
    int y = aTime->tm_year + 1900; // Year is # years since 1900
    year = int2str(y);
    month = int2str(m);
    day = int2str(d);
}

void input(){
    freopen("c.txt","r",stdin);
    
    getline(cin, mainkey);
    //getline(cin, subkey);
    getline(cin, desc);
    getline(cin, src);
    cin >> numOfImages;

    filename = mainkey;
    for(int i=0; i<filename.size(); i++){
        if(filename[i]==' ') 
        filename[i]='-';
    }
     
    postUrl = year + "/" + month + "/" + day + "/" + filename;
    imageFileName = filename;
    
    filename = year + "-" + month + "-" + day + "-" + filename + ".md";
    
    postUrl = websiteUrl+postUrl+".html";

    ImageUrl = websiteUrl+"coloring-pages/"+imageFileName;
}
int random(int minN, int maxN){
    return minN + rand() % (maxN + 1 - minN);
}
 
int main()
{
    srand((int)time(0));
    getday();
    input();
    ofstream fo(filename);
    fo << "---\n";
    fo << "layout: post" << endl;
    fo << "title: " << mainkey << endl;
    fo << "---\n\n";
    
    fo << "{{ page.title }}" << endl;
    fo << "================\n\n";
    
    fo << "This post is about " << mainkey << ". " << desc << " [Source: " << src <<"]" << endl << endl;

    int tt = random(0,4);
    fo << prePost[tt] << " [" << mainkey << "](" << postUrl << ") on [my coloring pages blog]("+websiteUrl +"). All these materials I've collected for my personal purpose - teaching my kids. You can use these for your personal use too." << endl;
    
    fo << endl;
    fo << "# **There are " << numOfImages << " \"" << mainkey << "\" in this webpage:**" << endl << endl;

    //fo << ads << endl << endl;

    for(int i=1; i<=numOfImages ; i++){
            
        fo << "## " << mainkey + " " + int2str(i) << endl << endl;

        fo << "![" << mainkey + " " + int2str(i) +"](";
        
        fo << ImageUrl << "-" << int2str(i)+".png)" << endl << endl;
        if(i==1){
            fo << ads << endl << endl;
        }
    }
    fo << ads << endl << endl;

    return 0;
}