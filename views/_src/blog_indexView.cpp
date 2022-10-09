#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT blog_indexView : public TActionView
{
public:
  blog_indexView() : TActionView() {}
  QString toString();
};

QString blog_indexView::toString()
{
  responsebody.reserve(1754);
  responsebody += QStringLiteral("<!DOCTYPE html>\n<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>Blog: index</title>\n  <script src=\"https://unpkg.com/vue@3\"></script>\n</head>\n<body>\n<div id=\"app\"></div>\n\n<!-- vue template -->\n<script type=\"text/x-template\" id=\"blog-index-template\">\n  <h1>Listing Blog</h1>\n  <p><a href=\"/blog/create\">Create a new Blog</a></p>\n  <table border=\"1\" cellpadding=\"5\" style=\"border: 1px #d0d0d0 solid; border-collapse: collapse;\">\n    <tr>\n      <th>ID</th>\n      <th>Title</th>\n      <th>Body</th>\n    </tr>\n    <tr v-for=\"item in items\">\n      <td>{{ item.id }}</td>\n      <td>{{ item.title }}</td>\n      <td>{{ item.body }}</td>\n      <td>\n        <a :href=\"`/blog/show/${item.id}`\">Show</a> <a :href=\"`/blog/save/${item.id}`\">Edit</a> <a href=\"#\" @click.prevent=\"postRemove(`/blog/remove/${item.id}`)\">Remove</a>\n      </td>\n    </tr>\n  </table>\n</script>\n\n<!-- vue app main -->\n<script>\nVue.createApp({\n  setup() {\n    return {\n      items: ");
  techoex2(items, ("{}"));
  responsebody += QStringLiteral("\n    };\n  },\n  template: \"#blog-index-template\",\n  methods: {\n    postRemove: function(url) {\n      if (confirm('Are you sure?')) {\n        var f = document.createElement('form');\n        document.body.appendChild(f);\n        f.method = 'post';\n        f.action = url;\n        var i = document.createElement('input');\n        f.appendChild(i);\n        i.type = 'hidden';\n        i.name = 'authenticity_token';\n        i.value = '");
  responsebody += THttpUtility::htmlEscape(authenticityToken());
  responsebody += QStringLiteral("';\n        f.submit();\n      }\n    }\n  }\n}).mount(\"#app\");\n</script>\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(blog_indexView)
