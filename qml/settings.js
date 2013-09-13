function getDatabase() {
return openDatabaseSync("wamod", "1.0", "WAMOD", 100000);
}
function init() {
var db = getDatabase();
db.transaction(
function(tx) {
tx.executeSql('CREATE TABLE IF NOT EXISTS settings(setting TEXT UNIQUE, value TEXT)');
tx.executeSql('CREATE TABLE IF NOT EXISTS kennzeichen(kennzeichen TEXT UNIQUE)');
});
}
function set(setting, value) {
init()
var db = getDatabase();
var res = "";
db.transaction(function(tx) {
var rs = tx.executeSql('INSERT OR REPLACE INTO settings VALUES (?,?);', [setting,value]);
if (rs.rowsAffected > 0) {
res = "OK";
} else {
res = "Error";
}
}
);
return res;
}
function get(setting) {
init()
var db = getDatabase();
var res="";
db.transaction(function(tx) {
var rs = tx.executeSql('SELECT value FROM settings WHERE setting=?;', [setting]);
if (rs.rows.length > 0) {
res = rs.rows.item(0).value;
} else {
res = "";
}
})
return res
}
function reset() {
var db = getDatabase();
db.transaction(function(tx) {
tx.executeSql('DROP TABLE settings')
})
db.transaction(function(tx) {
tx.executeSql('DROP TABLE kennzeichen')
})
}
