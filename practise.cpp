#include <bits/stdc++.h>
using namespace std;

//int searchInsert(vector<int>& nums, int target) {
//
//    int s = 0;
//    int e = nums.size() - 1;
//    int mid = s + (e-s)/2;
//
//    int found = -1;
//
//    if(target > nums[e]){
//        found = e-1;
//    }
//    else if(target < nums[s]){
//        found = 0;
//    }
//
//    while(e>=s){
//
//        if(nums[mid] == target){
//
//            found = mid;
//
//        }
//        else if(nums[mid] > target){
//
//            if(nums[mid] > target && target > nums[mid -1]){
//                found = mid;
//            }
//
//            e = mid - 1;
//
//        }
//        else{
//
//            if(nums[mid] < target && target < nums[mid + 1]){
//                found = mid + 1;
//            }
//
//            s = mid + 1;
//
//        }
//        mid = s + (e-s)/2;
//    }
//
//    return found;
//}

//void reverseArray(vector<int> &arr , int m)
//{
//    int n = arr.size();
//    int e = n - 1;
//    int s = m + 1;
//
//    while(e>s){
//
//        swap(arr[s],arr[e]);
//
//        s++;
//        e--;
//    }
//
//    for(int i=0; i<n ; i++){
//        cout<<arr[i]<<" ";
//    }
//}

//void moveZeroes(vector<int>& nums) {
//
//    int e = nums.size() ;
//    vector<int> zero;
//
//    int s = 0 ;
//
//    while(e>s){
//
//        if(nums[s] == 0){
//            nums.push_back(nums[s]);
//            zero.push_back(s);
//        }
//
//        s++;
//    }
//
//    int z = zero.size();
//
////    for(int i = 0; i<z ; i++){
////        nums.erase(nums.begin()+zero[i]);
////    }
//
//    for(int i=0;i<e;i++){
//        cout<<nums[i]<<" ";
//    }
//
//}

//int max_4(int a, int b, int c, int d)
//{
//    int x = max(a, max(b, max(c, d)));
//
//    return x;
//}
//
//int fourFriends(string & s) {
//    int first = 4;
//    int second = 8;
//    int third = 12;
//    int fourth = 16;
//
//    string x = "1";
//
//    int c1=0,c2=0,c3=0,c4=0;
//
//    int n = s.length();
//
//    while(n>0){
//        for(int i=0; i<first ;i++){
//            if(s[i]==x[0]){
//                c1++;
//            }
//        }
//        n = n -4;
//
//        for(int i=first ; i<second ;i++){
//            if(s[i]==x[0]){
//                c2++;
//            }
//        }
//        n = n -4;
//
//        for(int i=second ; i<third ;i++){
//            if(s[i]==x[0]){
//                c3++;
//            }
//        }
//        n = n -4;
//
//        for(int i=third ; i<fourth ;i++){
//            if(s[i]==x[0]){
//                c4++;
//            }
//            first = fourth +4;
//            second = first +4;
//            third = second +4;
//            fourth = third +4;
//        }
//        n = n -4;
//
//    }
//
//    int win = max_4(c1,c2,c3,c4);
//
//    if(win == c1){
//        win = 1;
//    }else if(win == c2){
//        win = 2;
//    }else if(win == c3){
//        win = 3;
//    }else{
//        win = 4;
//    }
//
//
//    string finalwin = "Yes " + to_string(win);
//
//    return c1;
//}


//int getsum(int n,int arr[n]){
//
//    cout<<sizeof(arr)<<endl;
//
//    int sum = 0;
//
//    for(int i=0; i<n ; i++){
//        sum += i[arr];
//    }
//    return sum;
//}

//vector<int> subarraySum(int arr[], int n, long long int s)
//{
//    vector<int> ans;
//    long long int sum = 0;
//    int st = 0;
//    int i = 0;
//
//    while(n>i){
//
//        sum += arr[i];
//
//        if(sum == s){
//
//            ans.push_back(st+1);
//            ans.push_back(i+1);
//            break;
//        }
//        else if(sum > s){
//
//            sum = sum - arr[st];
//            st++;
//
//            if(sum == s){
//                ans.push_back(st+1);
//                ans.push_back(i+1);
//                break;
//            }
//        }
//
//        i++;
//    }
//
//    return ans;
//}

int flipBits(int* arr, int n)
{
    int s = 0;
    int e = n - 1;
    int index = 0;
    int curr_sum=0;
    int ans = INT16_MIN;;
    int count = 2;

    while(s<=e){


        if(arr[s] == 0 && arr[s+1] == 1){
            count = 0;
        }
        else if(arr[s] == 1 || arr[s] == 0){
            count++;
        }

        s++;
        ans  = max(ans,count);
    }

    return ans;
}

int subarray(vector<int>& arr,int n,int k){

    int x = k;
    while(x--){
        for(int i=0; i<n ;i++){
            arr.push_back(arr[i]);
        }
    }

    int curr = 0;
    int ans = INT16_MIN;

    for(int i=0; i<n*k; i++){
        curr += arr[i];

        ans = max(curr,ans);

        if(curr < 0){
            curr = 0;
        }
    }

    return ans;

}

int goodness(int arr[],int& b,int& n){

    int bpoint = n/b ;
    int sum = 0;
    int next=0;

    for(int i=0 ; i<=n ;i++){
        if(i<bpoint){
            next = arr[i] | next;
        }
        else if(i == bpoint){
            sum = next + sum;
            next = 0;
        }
        else if(i > bpoint){
            next = arr[i-1] | next;
        }
        else if(i == bpoint * 2){
            next = arr[i-1] | next;
            sum = next + sum;
            next = 0;
            bpoint += bpoint;
        }
    }

    return sum;
}

int minSubarraySum(int arr[], int n, int k)
{
    int i = 0;
    int curr = 0;
    int ans = 2147483647;
    int m = k;
    while(n>i){
        while(m>0){
            curr += arr[i];
            m--;
            i++;
        }
        m = k;
        ans = min(curr,ans);
        i = k - i + 1;
    }

    return ans;
}

void superScore(int n, vector < int > arr) {

    vector<int> v;
    //    sort(arr.begin(),arr.end());
    int count = (n*(n+1)/2) ;
    int s = 0;
    int i = 0;
    int e = n;
    int curr = INT16_MAX;

    while(count > 0){

        if(s<=e){
            if(s == e){
                s = i+1;
                i++;
                curr = INT16_MAX;
            }
            curr = min(curr, arr[s]);
            v.push_back(curr*curr);
            s++;
        }

        count--;
    }

    long long int ans = 0;

    for(int j : v){
        ans += j;
    }

    for(int k : v){
        cout<<k<<" ";
    }
    cout<<endl;
    cout<<ans;
}

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    int a=0,b=0;
    int s=0,e=n-1;
    pair<int,int> p;

    sort(arr.begin(),arr.end());

    while(s<e){

        if(arr[s] == arr[s+1]){
            a = arr[s];
        }

        if((arr[s+1] - arr[s]) == 2){
            b = arr[s] + 1;
        }
        s++;
    }

    p.first = a;
    p.second = b;

    return p;
}

void reverse(string& s){
    stack<char> st;
    int x = s.length();
    int a=0;

    while (x--){

        char c = s[a];
        st.push(c);

        a++;
    }
    s.clear();
    int y = st.size();

    while (y--){

        char d = st.top();
        st.pop();
        s.push_back(d);

    }
}

int findMinimumCost(string str) {
    stack<char> s;

    if(str.size()%2 == 1){
        return -1;
    }

    for(int i =0; i<str.length() ; i++){
        char ch = str[i];

        if(ch == '{'){
            s.push(ch);
        }
        else{
            if(!s.empty()){
                char top = s.top();
                if(top == '{'){
                    s.pop();
                }
                else{
                    s.push(ch);
                }
            }
        }
    }

    int l = s.size();
    int a=0,b=0;

    while(l--){
        if(s.top() == '{'){
            a++;
        }
        else{
            b++;
        }
    }

    int cost = (a+1)/2 + (b+1)/2 ;

    return  cost;
}

string convertString(string str)
{
    //    char first = str[0]
    //    if(str[0] != toupper(str[0])){
    //        str[0] = toupper(str[0]);
    //    }

    for(int i=0; i<str.length() - 1 ;i++)
    {
        char ch = str[i];
        char next = str[i+1];
        if(ch == ' '){
            str[i+1] = toupper(next);
        }
    }

    return str;
}

void shop(){

    vector<pair<int,int>> v;
    pair<int,int> p;
    int n,m,l,r,pi;


    cin>>n>>m;

    while(n--){
        cin>>l>>r;
        p.first = l;
        p.second = r;

        v.push_back(p);
    }

    int size = v.size();

    while(m--){
        cin>>pi;
        int ans = INT_MAX;

        if(pi >= v[0].first && pi < v[0].second){
            cout<<0<<endl;
        }
        else{
            for(int i=1; i<size; i++){
                if(pi <= v[i].first){
                    int curr = v[i].first - pi;
                    ans = min(ans,curr);
                }
            }
            if(ans == INT_MAX)
                cout<<-1<<endl;
            else
                cout<<ans<<endl;
        }
    }

}

vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K)
{
    int i=0;
    long long int e=N-K+1;
    int s=0;
    int p=0;
    int q=1;
    vector<long long> v(e,0);

    while(e>0){

        if(A[i]<0){
            v[p] = A[i];
            p++;
            i=s;
            q=0;
            s++;
        }
        else if(q == K){
            q=0;
            i=s;
            s++;
            p++;
        }

        e--;
        q++;
        i++;
    }

    return v;

}

bool validstring(string s){

    int n = s.length();
    int num = 0;

    if(s[0] == '0'){
        return false;
    }

    if(n>3 || n == 0){
        cout<<"Mai"<<endl;
        return false;
    }

    int m = n-1;

    for(int i=0; i<n; i++){
        char c = s[i];
        num += (int(c) - 48) * pow(10,m);
        m--;
    }

    if(num < 0 || num > 255){
        cout<<num<<endl;
        cout<<"Nae Mai"<<endl;
        return false;
    }

    cout<<"Yrr Mai"<<endl;
    return true;
}

int isValid(string s) {

    int count=0;
    int n = s.length();

    for(int i=0; i<n; i++){

        char ch = s[i];

        if(ch == '.'){
            count++;
        }
    }

    if(count!=3){
        return 0;
    }

    string str;

    for (int j = 0; j <= n; j++) {

        char c = s[j];

        if (c == '.' || j == n) {
            if (!validstring(str)) {
                return 0;
            }

            str = "";
        }
        else {
            str += c;
        }

    }

    return 1;

}

void print_a(int n, vector<int> a){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

void sort012(int *arr){

    int x = sizeof(arr)/ sizeof(arr[0]);

    sort(arr,arr + x);
}

int binarysearch(int a[],int n,int key){
    int s,e;

    s = 0;
    e = n-1;

    while(s<=e){

        int mid = s + (e-s)/2 ;

        if(a[mid] == key){
            return mid;
        }

        if(key > a[mid]){
            s = mid + 1;
        }else{
            e = mid - 1;
        }

    }
    return -1;

}

vector<int> pairSum(vector<int> &arr, int s){

    vector<int> pair;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr.size() && j!=i;j++){
            if(arr[i] + arr[j] == s){
                pair.push_back(arr[i]);
                pair.push_back(arr[j]);
            }
        }
    }
    sort(pair.begin(),pair.end());

    return pair;
}

void findTriplets(vector<int>arr, int n, int K) {

    vector<vector<int>> ans;
    vector<int> temp;

    sort(arr.begin(),arr.end());

    for(int i=0 ; i<n ; i++){

        if((arr[i] + arr[i+1] + arr[i+2]) == K){

            temp.push_back(arr[i]);
            temp.push_back(arr[i+1]);
            temp.push_back(arr[i+2]);
            break;
        }else if ((arr[i] + arr[i+2] + arr[i+3]) == K){

            temp.push_back(arr[i]);
            temp.push_back(arr[i+2]);
            temp.push_back(arr[i+3]);
            break;
        }
    }

    ans.push_back(temp);

    //print_a(ans.size(),ans);
}

void trappingWater(int arr[], int n){
    // code here
    int left[n],right[n];

    left[0]=arr[0];

    right[n-1]=arr[n-1];

    for(int i=1;i<n;i++){

        left[i]=max(left[i-1],arr[i]);

    }

    for(int i=1;i<n;i++){

        right[n-i-1]=max(right[n-i],arr[n-i-1]);

    }

    long long ans=0;

    for(int i=0;i<n;i++){

        ans+=min(left[i],right[i])-arr[i];

    }

    cout<<"Right ";for(auto i : left){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Left ";for(auto i : right){
        cout<<i<<" ";
    }
}

void sortByBits(vector<int>& arr) {

    vector<int> ans;
    vector<pair<int,int>> bits;

    for(int i=0; i<arr.size(); i++){
        int bit = 0;
        int val = arr[i];
        while(val != 0){
            if(val & 1 == 1){
                bit++;
            }
            val >>= 1;
        }
        pair<int,int> p =  make_pair(bit,arr[i]);
        bits.push_back(p);
    }

    sort(bits.begin(),bits.end());

    for(auto i: bits){
        cout<<i.first<<" "<<i.second<<" "<<endl;
    }
}

void substrings(string s,vector<string>& sub){

    int i=0;
    int n=3;
    int k=0;

    while(n < s.length()){
        string str;
        int j=0;

        while(j < n){
            str.push_back(s[i++]);
            j++;
        }

        sub.push_back(str);

        if(i > s.length()-1){
            i=0;
            k=0;
            n++;
        }
        else{
            i = k+1;
            k++;
        }
    }

    sub.push_back(s);
}

int beauty(string s){

    int maxi = INT16_MIN;
    int mini = INT16_MAX;
    map<char,int> count;

    for(int i=0; i<s.length(); i++){
        count[s[i]]++;
    }

    for(int i=0; i<s.length(); i++){
        maxi = max(maxi,count[s[i]]);
        mini = min(mini,count[s[i]]);
    }

    return maxi-mini;
}

int beautySum(string s) {
    vector<string> sub;

    substrings(s,sub);

    int b= 0;
    for(int i=0; i<sub.size(); i++){
        int val = beauty(sub[i]);
        b += val;
    }

    return b;
}

int removeStones(vector<vector<int>>& stones) {

    int count=0;
    vector<pair<int,int>> v;

    for(int i=0; i<stones.size(); i++){
        pair<int,int> p;
        p = make_pair(stones[i][0],stones[i][1]);
        v.push_back(p);
    }

    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            if(v[i].first == v[j].first || v[i].second == v[j].second){
                count++;
                break;
            }
        }
    }

    return count;
}

//void position(int a[],int n,int k){
//
//    int first=0,last=0;
//
//    vector<int> ans;
//
//     for(int i=0;i<n;i++){
//         if(a[i] == a[i+1]){
//             first = i;
//             ans.push_back(i);
//             for(int j=i;j<n;j++){
//                 if(a[j] != a[j+1]){
//                     last = j;
//                     ans.push_back(j);
//                     break;
//                 }
//             }
//             break;
//         }
//     }
//    print_a(ans.size(),ans);
//}

//LL
class Node
{
public:
    int data;
    Node *next;

    explicit Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

Node * uniqueSortedList(Node* &head) {

    Node* curr = head;
    map<int,bool> visited;

    while(curr!=nullptr){

        if(visited[curr->data] && curr->next != nullptr){
            Node* insert = curr->next->next;
            curr->next = insert;
            Node* todelete = curr->next;
            delete(todelete);
        }
        else{
            visited[curr->data] = true;
            curr = curr->next;
        }
    }

    return head;
}

void inserthead(Node* &n1,int d){

    Node* temp = new Node(d);
    temp->next = n1;
    n1 = temp;
}

Node* adjacent(Node* &head){

    Node* curr = head;

    while(curr!=nullptr){
        if((curr->next!=nullptr) && (curr->data == curr->next->data)){
            Node* todelete = curr->next;
            Node* insert = curr->next->next;
            curr->next = insert;
            delete(todelete);
        }
        else{
            curr = curr->next;
        }
    }

    return head;
}

bool checkpalindrome(vector<int> v){

    int n = v.size();
    int s = 0;
    int e = n-1;

    while(s<=e){

        if(v[s] != v[e]){
            return  0;
        }
        s++;
        e--;
    }

    return 1;
}

bool vectorr(Node* head){

    vector<int> store;
    Node* temp = head;

    while (temp != nullptr){
        int value = temp->data;
        store.push_back(value);
        temp = temp->next;
    }

    bool ans = checkpalindrome(store);

    return ans;
}

int len(Node* head)
{
    int count = 0;
    Node* current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

Node* add(Node* first,Node* second){

    int firstno = 0;
    int secondno = 0;

    Node* temp1 = first;
    Node* temp2 = second;

    int f = len(temp1);
    int s = len(temp2);

    while (temp1 != NULL){
        int value = temp1->data;
        firstno += value * pow(10, f-1);
        f--;
        temp1 = temp1->next;
    }

    while (temp2 != NULL){
        int value = temp2->data;
        secondno += value * pow(10, s-1);
        s--;
        temp2 = temp2->next;
    }

    int sum = firstno + secondno;
    int x = sum;
    Node* ans = NULL;
    Node * head = ans;

    while (sum>0){
        int digit = sum%10;
        sum /= 10;
        inserthead(head,digit);
    }

    return head;
}