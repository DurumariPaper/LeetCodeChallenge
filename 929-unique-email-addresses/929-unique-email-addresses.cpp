class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        // hash set to store all the unique emails
        unordered_set<string> uniqueEmails;

        for (string email : emails) {
            string cleanEmail = "";

            // iterate over each character in email
            for (char ch : email) {
                // stop adding characters to localName
                if (ch == '+' || ch == '@') break;

                // skip this character
                if (ch == '.') continue;

                cleanEmail += ch;
            }

            string domainName;
            for (int i = email.size()-1; i >= 0; --i) {
                char currChar = email[i];
                domainName += currChar;
                if (currChar == '@') break;
            }

            reverse(domainName.begin(), domainName.end());
            cleanEmail += domainName;

            // insert the email formed in hashset
            uniqueEmails.insert(cleanEmail);
        }

        // return count of unique emails
        return uniqueEmails.size();
    }
};