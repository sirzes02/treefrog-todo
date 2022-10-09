#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT blog_createView : public TActionView
{
public:
  blog_createView() : TActionView() { }
  QString toString();
};

QString blog_createView::toString()
{
  responsebody.reserve(1493);
  responsebody += QStringLiteral("<!DOCTYPE html>\n<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>Blog: create</title>\n  <script src=\"https://unpkg.com/vue@3\"></script>\n</head>\n<body>\n<div id=\"app\"></div>\n\n<!-- vue template -->\n<script type=\"text/x-template\" id=\"blog-create-template\">\n  <h1>New Blog</h1>\n  <p style=\"color: red\">{{ error }}</p>\n  <p style=\"color: green\">{{ notice }}</p>\n  <form action=\"/blog/create\" enctype=\"multipart/form-data\" method=\"post\">\n    <input type=\"hidden\" name=\"authenticity_token\" :value=\"authenticity_token\" />\n    <p>\n      <label>Title<br><input type=\"text\" name=\"blog[title]\" :value=\"item.title\" /></label>\n    </p>\n    <p>\n      <label>Body<br><input type=\"text\" name=\"blog[body]\" :value=\"item.body\" /></label>\n    </p>\n    <p>\n      <input type=\"submit\" value=\"Create\" />\n    </p>\n  </form>\n  <a href=\"/blog/index\">Back</a>\n</script>\n\n<!-- vue app main -->\n<script>\nVue.createApp({\n  setup() {\n    return {\n      item: ");
  techoex2(item, ("{}"));
  responsebody += QStringLiteral(",\n      error: '");
  tehex(error);
  responsebody += QStringLiteral("',\n      notice: '");
  tehex(notice);
  responsebody += QStringLiteral("',\n      authenticity_token: '");
  responsebody += THttpUtility::htmlEscape(authenticityToken());
  responsebody += QStringLiteral("',\n    };\n  },\n  template: \"#blog-create-template\",\n}).mount(\"#app\");\n</script>\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(blog_createView)

