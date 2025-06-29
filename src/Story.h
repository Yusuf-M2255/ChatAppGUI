//
// Created by M.Ramadan on 4/16/25.
//

#ifndef STORY_H
#define STORY_H
#include<set>
#include<ctime>
#include<iostream>

#include "User.h"
#include "Date.h"
class Date;

using namespace std;
using json = nlohmann::json;


class Story {
    int userId;
    tm publishTime;
    string storyPhotoPath;
    string storyText;
    set<int> excludedIds;
    inline static vector<Story> stories;
    string storyColor;

public:
    Story(const int &userId,
          const tm &publishTime,
          const string &storyText,
          const string &storyPhotoPath,
          const set<int> &excludedIds);

    Story(const int &userId,
          const tm &publishTime,
          const string &storyText,
          const string &storyPhotoPath,
          const set<int> &excludedIds,
          const string& storyColor
          );

    void setId(const int &id);

    int getId() const;

    void setPublishTime(const tm &publishTime);

    tm getPublishTime() const;

    void setStoryPhotoPath(const string &storyPhotoPath);

    string getStoryPhotoPath() const;

    void setStoryText(const string &storyText);

    string getStoryText() const;

    void setStoryColor(const string& storyColor);

    string getStoryColor() const;

    static Story fromJson(const json &json);

    json toJson();

    bool isExpired() const;

    void excludeContact(const int &id);

    void includeContact(const int &id);

    bool isExcluded(const int &id) const;

    bool operator<(const Story &story) const;

    static void readStories();

    static void writeStories();

    static set<Story> retrieveStoriesByUserId(const int &userId);

    void save();
};


#endif //STORY_H
