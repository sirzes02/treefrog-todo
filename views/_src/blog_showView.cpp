#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT blog_showView : public TActionView
{
public:
  blog_showView() : TActionView() { }
  QString toString();
};

QString blog_showView::toString()
{
  responsebody.reserve(1233);
  responsebody += QStringLiteral("<!DOCTYPE html>\n<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>Blog: show</title>\n  <script src=\"https://unpkg.com/vue@3\"></script>\n</head>\n<body>\n<div id=\"app\"></div>\n\n<!-- vue template -->\n<script type=\"text/x-template\" id=\"blog-show-template\">\n  <h1>Showing Blog</h1>\n  <p style=\"color: red\">{{ error }}</p>\n  <p style=\"color: green\">{{ notice }}</p>\n  <dt>ID</dt><dd>{{ item.id }}</dd><br>\n  <dt>Title</dt><dd>{{ item.title }}</dd><br>\n  <dt>Body</dt><dd>{{ item.body }}</dd><br>\n  <dt>Created at</dt><dd>{{ item.createdAt }}</dd><br>\n  <dt>Updated at</dt><dd>{{ item.updatedAt }}</dd><br>\n  <dt>Lock Revision</dt><dd>{{ item.lockRevision }}</dd><br>\n  <a :href=\"`/blog/save/${item.id}`\">Edit</a> |\n  <a href=\"/blog/index\">Back</a>\n</script>\n\n<!-- vue app main -->\n<script>\nVue.createApp({\n  setup() {\n    return {\n      item: ");
  techoex2(item, ("{}"));
  responsebody += QStringLiteral(",\n      error: '");
  tehex(error);
  responsebody += QStringLiteral("',\n      notice: '");
  tehex(notice);
  responsebody += QStringLiteral("',\n    };\n  },\n  template: \"#blog-show-template\",\n}).mount(\"#app\");\n</script>\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(blog_showView)

