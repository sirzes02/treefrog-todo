#include "blogservice.h"
#include "objects/blog.h"
#include <TreeFrogModel>


void BlogService::index()
{
    auto items = Blog::getAllJson();
    texport(items);
}

void BlogService::show(int id)
{
    auto item = Blog::get(id).toJsonObject();
    texport(item);
}

int BlogService::create(THttpRequest &request)
{
    auto item = request.formItems("blog");
    auto model = Blog::create(item);

    if (model.isNull()) {
        QString error = "Failed to create.";
        texport(error);
        texport(item);
        return -1;
    }

    QString notice = "Created successfully.";
    tflash(notice);
    return model.id();
}

void BlogService::edit(TSession& session, int id)
{
    auto model = Blog::get(id);
    if (!model.isNull()) {
        session.insert("blog_lockRevision", model.lockRevision());
        auto item = model.toJsonObject();
        texport(item);
    }
}

int BlogService::save(THttpRequest &request, TSession &session, int id)
{
    int rev = session.value("blog_lockRevision").toInt();
    auto model = Blog::get(id, rev);
    
    if (model.isNull()) {
        QString error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        return 0;
    }

    auto item = request.formItems("blog");
    model.setProperties(item);
    if (!model.save()) {
        texport(item);
        QString error = "Failed to update.";
        texport(error);
        return -1;
    }

    QString notice = "Updated successfully.";
    tflash(notice);
    return 1;
}

bool BlogService::remove(int id)
{
    auto blog = Blog::get(id);
    return blog.remove();
}

