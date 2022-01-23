void solve
{
    int n;
    cin >> n;

    vector<vector<int>> A(n);

    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        V[i].push_back(0);
        for (char c : s)
        {
            if (c == '.')
                A[i].push_back(0);
            else
                A[i].back() = A[i].back() * 10 + (c - 48);
        }
    }

    sort(A.begin(), A.end());

    bool dot = false;

    for (auto n : A.back())
    {
        if (dot)
            cout << ".";
        cout << n;
        dot = true;
    }
}
