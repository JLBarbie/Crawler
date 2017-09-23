#include "crawler.h"

#include <iostream>

Crawler::Crawler()
{
//    m_config = loadConfig();
//    if (m_config["drop_db"]) {
//        db->dropTables(m_config["items"]);
//    }
//    @db.createTables(@config["items"]);
//    @db.push($config["url"]);
//    if $config["debug"] == "true"
//      Log.info("Debug Mode Enable".light_yellow)
}

int Crawler::run()
{
    std::cout << "Start Crawler" << std::endl;
    return 0;
}

int Crawler::spider(size_t padding)
{
//    url_current, url_id = getUrlCurrent(padding);
//    if (url_current.force_encoding("UTF-8").ascii_only?) {
//        try {
//            html_src = open(url_current, "User-Agent" => @config["user-agent"], :allow_redirections => :safe);
//            page = Nokogiri::HTML(html_src);
//            searchLink(page);
//            if ($config["table"] == "false") {
//                searchBySelector(page);
//                Log.success(url_current);
//            } else if ($config["table"] == "true")
//                searchOnTable(page);
//            }
//        } catch e {
//            if (e) {
//                when OpenURI::HTTPError;
//                Log.error(e.to_s);
//                Log.debug(url_current, $config["debug"]);
//            } else {
//                Log.error(e.to_s);
//            }
//        }
//    }
//    if (db->countUrl > 1)
//        db->updateStatus(url_id);
}

/*!
 * \brief Crawler::searchLink
 *
 * Recupere les liens dans une page
 */
void Crawler::searchLink(page) {
//    links = page.css("a").map { |link| link["href"].to_s }.uniq.sort.delete_if(&:empty?)
//    links.delete_if { |link| !link.start_with?(@config["url"], "/") }
//    links.each { |link| @db.push(link) }
}

void Crawler::searchBySelector(page) {
//  data = {};
//  $config["items"].each do |key, value| {
//        if value.start_with?("input") {
//            data[key] = page.value(value).text;
//        } else if key.start_with?("dc-") {
//            if (page.css(value)[0]) {
//                data[key] = page.css(value)[0]["data-content"];
//            }
//        } else {
//            data[key] = page.css(value).text;
//        }
//    }
//    unless (data.empty?) {
//        @db.putsData(data);
//    }
}

void searchOnTable(page)
{
//    page.search("table").each do |table|
//    {
//        table.search("tr").each do |row|
//        {
//            row.search("td").each do |td|
//            {
//                @fd.print "" + td.text.strip + ", "
//            }
//            @fd.print ";\n"
//        }
//    }
}

UrlCurrent Crawler::getUrlCurrent(padding = 0)
{
//    UrlCurrent current = db->pop(padding);
//    if (!url_check == NULL) {
//        Log.debug("(Open)   : ".light_white + url_check, $config["debug"]);
//    } else {
//        Log.error("Url_check not found");
//    }

//    if (url_check.to_s.start_with("//"))
//    {
//        url_current = "http:" + url_check;
//    }
//    else if (url_check.to_s.start_with("/"))
//    {
//        url_current = config["url"].chomp("/") + url_check.to_s;
//    }
//    else if (!url_check.to_s.start_with("http") && !url_check.to_s.start_with("//"))
//    {
//        url_current = config["url"].chomp("/") + "/" + url_check.to_s;
//    }
//    else if (url_check.to_s.include("facebook"))
//    {
//        @db.updateStatus(url_id);
//        return;
//    }
//    else if (!url_check.to_s.include(config["url"]))
//    {
//        @db.badLink(url_id);
//        return;
//    }
//    else
//    {
//        url_current = url_check.to_s;
//    }

//    if (config["partial"] != NULL)
//        return checkPartial(url_current, url_id);
//    return url_current, url_id;
}

UrlCurrent Crawler::checkPartial(url, id)
{
//    if (url.include(config["partial"]))
//        return url, id;
//    else {
//        Log.debug("Not in partial " + url, $config["debug"]);
//        @db.badLink(id);
//        sleep(config["sleeper"]);
//        getUrlCurrent;
//    }
}

/*
  #-------------------------------------#
  # METHODE DE CRAWLING                 #
  #-------------------------------------#
  def fromConfig
    t = {}
    # spider(1)
    thread = @config["thread"].to_i
    while @db.countUnreaded > 0
      thread.times do |i|
        t[i] = Thread.new { spider(i) }
      end
      Log.debug("[Nb URL unread] : ".light_white + @db.countUnreaded.to_s, $config["debug"])
      if (@config["sleeper"]).to_i.nonzero?
        sleep(@config["sleeper"].to_i)
      end
    end
    Log.info("No more link, Bye")
    Log.info("Nb errors : " + $errorCount.to_s)
    exit
  end
end

*/
