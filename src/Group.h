//
// Created by dell on 4/20/2025.
//

#ifndef GROUP_H
#define GROUP_H
#include "ChatRoomModel.h"
#include <string>
using namespace std;
class Group : public ChatRoomModel {

    string ImagePath;
    string Description;
    bool Type_Permission;

public:
    enum Roles {
        NOT_MEMBER=0,
        MEMBER=1,
        ADMIN=2,
        OWNER=3
    };
    map<int,Roles> Members_Roles;
    Group();
    Group(
        string name,
        vector<int> &users,
        set<MessageModel> &messages,
        map<int,Roles> &MemberRoles,
        string ImagePath,
        string Description,
        bool Type_Permission
    );
    Group(
        long long Id,
        string name,
        vector<int> &users,
        set<MessageModel> &messages,
        map<int,Roles> &MemberRoles,
        string ImagePath,
        string Description,
        bool Type_Permission
    );
    static Group* createGroup(string name, int adminId, string imagePath, string descreption, bool type_perm);
    const string& getImagePath() const;
    const string& getDescription() const;
    Roles getRoleOf(int Member) const;
    bool isMember(int userId);
    map<int, Roles> getRoles();
    void setImagePath(string &ImagePath);
    void setDescription(string &Description);
    bool getTypePermission();
    void setTypePermission(bool TypePermission);
    void Change_Member_Role(int member,Roles Role);
    void Change_Member_Role(User& member,Roles Role);
    void Add_Member(int Member);
    void Remove_Member(int Member);
    void deleteGroup();
    static string roleToString(Roles role);

    static Group* fromJson(const json &json);
    json toJson() override;
};



#endif //GROUP_H
