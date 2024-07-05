#include<iostream>
#include<vector>
using namespace std;
class Post{
    public:
    int userid;
    int postid;
    Post(int userid,int postid){
        this->userid=userid;
        this->postid=postid;
    }
};
class Story{
    public:
    int userid;
    int stryid;
    Story(int userid,int stryid){
        this->userid=userid;
        this->stryid=stryid;
    }
};
class Follow{
    public:
    int userid1;
    int userid2;
    Follow(int userid1,int userid2){
        this-> userid1=userid1;
        this-> userid2=userid2;
    }
};
class Instagram{
    private:
    vector<Post> posts;//Created vectors of classes/usr dfnd data structures
    vector<Story> stories;
    vector<Follow> follows;
    public:
    Instagram(){}
    void post(int userid,int postid){
        for(int i=0;i<posts.size();i++){
            if(posts[i].postid==postid ){
                cout<<endl<<"Post id must be unique"<<endl;
                return;
            }

        }
        posts.push_back(Post(userid,postid));
    }
    void upload_story(int userid,int stryid){
        for(int i=0;i<stories.size();i++){
            if(stories[i].userid==userid && stories[i].stryid==stryid){
                cout<<endl<<"Error Duplicate"<<endl;
                return;
            }
        }
        stories.push_back(Story(userid,stryid));
    }
    void follow(int userid1,int userid2){
        for(int i=0;i<follows.size();i++){
            if(follows[i].userid1==userid1 && follows[i].userid2==userid2){
                cout<<userid1<<" already follows "<<userid2<<endl;
                return;
            }
        }
        follows.push_back(Follow(userid1,userid2));
    }
    void unfollow(int userid1,int userid2){
        for(int i=0;i<follows.size();i++){
            if(follows[i].userid1==userid1 && follows[i].userid2==userid2){
                follows.erase(follows.begin()+i);
                cout<<"User "<<userid1<<" successfully unfollowed "<<"User "<<userid2;
            } 
            --i;
        }
    }
    vector<int> get_stories(int userid){
        vector<int> results;
        int n=stories.size()-1;
        cout<<endl;
        for(int i=n;i>=0;i--){
            if(stories[i].userid == userid){
                cout<<stories[i].stryid<<" ";
                results.push_back(stories[i].stryid);
            }
        }
        return results;
    }
    vector<int> feed(int userid){
        vector<int> results;
        int n=posts.size()-1;
        cout<<endl;
        for(int i=n;i>=0;i--){
            if(posts[i].userid==userid){
                cout<<posts[i].postid<<" ";
                results.push_back(posts[i].postid);
            }
        }
        return results;
    }
};
int main(){
    Instagram insta;
    insta.post(1,453);//posting any post
    insta.post(1,234);
    insta.post(1,675);
    insta.post(2,323);
    insta.post(3,456);
    insta.post(2,343);
    insta.feed(1);//thsi will return a vector of post and also print them.
    insta.upload_story(1,78);
    insta.upload_story(2,79);//uploading any story
    insta.upload_story(1,78);//getting error of duplicate story and userid.
    insta.follow(1,2);//adding followers
    insta.follow(1,2);// Getting error because 1 already follows 2.
    insta.unfollow(1,2);// unfollow
    insta.get_stories(1);//this will return a vector of stories and also print them.
  

    

    return 0;
}