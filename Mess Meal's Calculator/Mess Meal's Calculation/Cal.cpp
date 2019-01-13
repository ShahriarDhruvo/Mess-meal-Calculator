#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector < pair<string, int> > mp;
    vector < pair<string, int> >::iterator it0;
    vector < pair<string, int> > mp1;
    vector < pair<string, int> >::iterator it2;
    vector < pair<int, int> > mp2;
    vector < pair<int, int> >::iterator it3;
    vector <string> vec1;

    int n, grandsum = 0, totalMeal = 0, l;
    float mealRate, cal;
    cout << "Enter the number of people in your mess: ";
    cin >> l;

    for(n=1; n<=l; n++) {
        string member;
        int i = 1, x, sum = 0, meal;
        vector <int> vec;
        cout << "*** Member no. " << n << ": " <<"Enter a member's name : ";
        getline(cin, member);
        getline(cin, member);
        vec1.push_back(member);
        cout << "\n" << member << "'s Bazar List : " << "\n" << endl;
        while(1) {
            cout << "Bazar No. " << i << " (Taka)" << " : ";
            cin >> x;
            if(x == 0) break;
            vec.push_back(x);
            i++;
        }
        cout << member << "'s total meal : ";
        cin >> meal;
        vector <int>::iterator it1;
        for(it1 = vec.begin(); it1 != vec.end(); it1++) {
            sum = sum + *it1;
        }
        cout << "\n" <<member << "'s Total Bazar (Taka): " << sum << "\n" << endl;
        mp.push_back(make_pair(member, sum));
        mp1.push_back(make_pair("Number of meals : ", meal));
        mp2.push_back(make_pair(meal, sum));
        grandsum = grandsum + sum;
        totalMeal = totalMeal + meal;
    }
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;

    cout << endl;
    for(it0 = mp.begin(), it2 = mp1.begin(); it0 != mp.end(), it2 != mp1.end(); it0++, it2++) {
        cout << it0->first << "'s total cost: " << "\t  " << it0->second << "\t" << it2->first << "\t" << it2->second << endl;
    }
    cout << "\n" << "Total Meal Cost: " << grandsum << "\t" << "Total Meal: " << totalMeal << "\n" << endl;
    mealRate = (float)grandsum/(float)totalMeal;
    printf("Meal Rate: %0.4f\n\n", mealRate);
    cout << "Everyone's GIVE & GET calculations: \n" << endl;
    n = 0;
    for(it3 = mp2.begin(); it3 != mp2.end(); it3++) {
        cal = (mealRate*it3->first) - it3->second;
        if(cal < 0)
            cout << vec1[n] << " will get " << "\t: " << ceil(abs(cal)) << " taka" << endl;
        else cout << vec1[n] << " will give" << "\t: " << ceil(cal) << " taka" << endl;
        n++;
        cal = 0.0;
    }

    cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
    int m;
    cin >> m;

    return 0;
}
