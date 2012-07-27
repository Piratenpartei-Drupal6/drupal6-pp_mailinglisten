$(document).ready(function() {
	if (typeof pp_mailinglisten !== "undefined") {
		$.ajax({
			type: "GET",
			url: "/stats.php",
			dataType: "xml",
			cache: false,
			success: function(xml) {
				var hrefs = {};
				$("table.mailinglisten td:first-child a").each(function(idx, a) {
					var href = $(a).attr("href");
					href = href.replace(/cgi-bin\/mailman/, "mailman");
					$(a).attr("href", href);
					href = href.replace(/mailman/, "cgi-bin/mailman");
					hrefs[href] = a;
				});

				$(xml).find('list').each(function() {
					var url = $(this).attr("url");
					url = url.toLowerCase();

					if (hrefs[url]) {
						var members = $(this).attr("members");
						$(hrefs[url]).parent().next().html(members);
					}
				});
			},
			error: function(jqXHR, textStatus, errorThrown) {
				console.log(textStatus);
				console.log(jqXHR);
			}
		});
	}
});