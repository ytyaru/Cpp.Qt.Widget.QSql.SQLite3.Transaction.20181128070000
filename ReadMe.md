# このソフトウェアについて

　Qt5学習。QtでSQLite3を使いトランザクションした。

　ついでにファイルパスを渡すときのバグを修正した。

## 前回まで

* https://github.com/ytyaru/Cpp.Qt.Widget.QSql.SQLite3.Class.20181127180000
* https://github.com/ytyaru/Cpp.Qt.Widget.QSql.SQLite3.Class.20181127170000
* https://github.com/ytyaru/Cpp.Qt.Widget.QSql.SQLite3.Class.20181127160000
* https://github.com/ytyaru/Cpp.Qt.Widget.QSql.SQLite3.Class.20181127130000

## コード抜粋

memodb.cpp
```cpp
void MemoDb::Write(QStringList record)
{
    QSqlDatabase db = QSqlDatabase::database(this->dbName);
    db.transaction();
    try {
        QSqlQuery query(db);
        query.prepare("insert into Memo (Memo, DateTime) values (?, ?)");
        for (int i = 0; i < record.size(); i++) {
            query.bindValue(i, record[i]);
        }
        query.exec();
//        throw "SomeException";
        db.commit();
        qDebug() << "QSqlDatabase::commit()";
    } catch (...) {
        qDebug() << "QSqlDatabase::rollback()";
        db.rollback();
    }
}
```

# 参考

* http://tomokiit.hatenablog.jp/entry/Qt_SQLite
* https://blogs.yahoo.co.jp/hmfjm910/10815002.html
* https://forum.qt.io/topic/18700/sqlite-connection-qsqldatabaseprivate-adddatabase-duplicate-connection-name-qt_sql_default_connection-old-connection-removed/7
* http://doc.qt.io/archives/qt-4.8/sql-sqlstatements.html

## Qt要素

* http://doc.qt.io/qt-5/qsql.html
    * http://doc.qt.io/qt-5/qsqldatabase.html
    * http://doc.qt.io/qt-5/qsqlquery.html

# 開発環境

* [Raspberry Pi](https://ja.wikipedia.org/wiki/Raspberry_Pi) 3 Model B+
    * [Raspbian](https://www.raspberrypi.org/downloads/raspbian/) GNU/Linux 9.0 (stretch) 2018-06-27
        * Qt 5.7.1

## 環境構築

* [Raspbian stretch で Qt5.7 インストールしたもの一覧](http://ytyaru.hatenablog.com/entry/2019/12/17/000000)

# ライセンス

　このソフトウェアはCC0ライセンスである。

[![CC0](http://i.creativecommons.org/p/zero/1.0/88x31.png "CC0")](http://creativecommons.org/publicdomain/zero/1.0/deed.ja)

## 利用ライブラリ

ライブラリ|ライセンス|ソースコード
----------|----------|------------
[Qt](http://doc.qt.io/)|[LGPL](http://doc.qt.io/qt-5/licensing.html)|[GitHub](https://github.com/qt)

* [参考1](https://www3.sra.co.jp/qt/licence/index.html)
* [参考2](http://kou-lowenergy.hatenablog.com/entry/2017/02/17/154720)
* [参考3](https://qiita.com/ynuma/items/e8749233677821a81fcc)
